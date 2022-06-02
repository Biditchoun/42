/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   args_print.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: swijnber <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/23 17:18:59 by swijnber          #+#    #+#             */
/*   Updated: 2022/06/02 14:50:11 by swijnber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

static void	pwidth_det(const char *s, va_list args, t_f lag, char type)
{
	int	i;

	i = -1;
	while (s[++i] != type)
		if (s[i] == '.' && s[i + 1] == '*')
			lag.pwidth = va_arg(args, int);
	if (lag.point && lag.point[1] != '*')
		lag.pwidth = ft_atoi(&lag.point[1]);
}

static void	width_det(const char *s, va_list args, t_f lag, char type)
{
	int	i;

	pwidth_det(s, args, lag, type);
	i = -1;
	while (s[++i] != type)
		if (s[i] == '*' && s[i - 1] != '.')
			lag.width = va_arg(args, int);
	lag.width_ptr = ft_strnrchr(s, '*', i);
	while (i > -1)
	{
		while (i > -1 && (!ft_isdigit(s[i]) || s[i] == '0'))
			i--;
		while (i > -1 && ft_isdigit(s[i]))
			i--;
		if ((i > -1 && s[i] != '.') || (i == -1 && ft_isdigit(s[i + 1])))
			break ;
	}
	if (++i > 0 && &s[i] > lag.width_ptr)
		lag.width_ptr = (char *)&s[i];
	if (i > 0 && (char *)&s[i] == lag.width_ptr)
		lag.width = (ft_atoi(&s[i]));
}

int	printfing(const char *s, va_list args, t_f lag, char type)
{
	char	*print;
	int		rt;

	width_det(s, args, lag, type);
	print = NULL;
	if (type == 'c')
		print = printf_char(lag, va_arg(args, int));
	else if (type == 's')
		print = printf_str(lag, va_arg(args, char *));
	else if (type == 'p')
		print = printf_void(lag, va_arg(args, void *));
	else if (type == 'd' || type == 'i')
		print = printf_int(lag, va_arg(args, int));
	else if (type == 'u')
		print = printf_uint(lag, va_arg(args, unsigned int));
	else if (type == 'x' || type == 'X')
		print = printf_hex(lag, va_arg(args, unsigned long long), type);
	else if (type == '%')
		print = printf_char(lag, '%');
	if (!print)
		return (0);
	rt = ft_strlen(print);
	write(1, print, rt);
	free(print);
	return (rt);
}
