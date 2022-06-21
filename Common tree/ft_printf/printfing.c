/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   args_print.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: swijnber <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/23 17:18:59 by swijnber          #+#    #+#             */
/*   Updated: 2022/06/21 10:33:46 by swijnber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static t_f	pwidth_det(const char *s, va_list args, t_f lag, char type)
{
	int	i;

	i = -1;
	while (s[++i] != type)
		if (s[i] == '.' && s[i + 1] == '*')
			lag.pwidth = va_arg(args, int);
	if (lag.point && lag.point[1] != '*')
		lag.pwidth = ft_atoi(&lag.point[1]);
	return (lag);
}

static t_f	width_det(const char *s, va_list args, t_f lag, char type)
{
	int	i;

	lag = pwidth_det(s, args, lag, type);
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
	if (&s[++i] > lag.width_ptr)
		lag.width_ptr = (char *)&s[i];
	if ((char *)&s[i] == lag.width_ptr)
		lag.width = (ft_atoi(&s[i]));
	return (lag);
}

static int	gniftnirp(t_f lag, int c, char *print)
{
	int	rt;

	if (!print)
		return (0);
	if (c)
		rt = ft_strlen(print);
	else if (!lag.minus)
		rt = ft_strlen(print) + 1;
	else
		rt = ft_strlen(&print[1]) + 1;
	write(1, print, rt);
	free(print);
	return (rt);
}

int	printfing(const char *s, va_list args, t_f lag, char type)
{
	char	*print;
	int		c;

	lag = width_det(s, args, lag, type);
	print = NULL;
	c = -1;
	if (type == 'c')
		c = va_arg(args, int);
	if (type == 'c')
		print = printf_char(lag, c);
	else if (type == 's')
		print = printf_str(lag, va_arg(args, char *));
	else if (type == 'p')
		print = printf_void(lag, va_arg(args, void *));
	else if (type == 'd' || type == 'i')
		print = printf_int(lag, va_arg(args, int));
	else if (type == 'u')
		print = printf_uint(lag, va_arg(args, unsigned int));
	else if (type == 'x' || type == 'X')
		print = printf_hex(lag, va_arg(args, unsigned int), type);
	else
		print = printf_char(lag, type);
	return (ft_25(lag, c, print));
}
