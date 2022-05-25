/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   args_print.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: swijnber <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/23 17:18:59 by swijnber          #+#    #+#             */
/*   Updated: 2022/05/25 21:40:13 by swijnber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

static void	pwidth_det(const char *s, va_list args, t_list flag_list, char type)
{
	int	i;

	flag_list.pwidth = 0;
	flag_list.width = 0;
	i = -1;
	while (s[++i] != type)
		if (s[i] == '.' && s[i + 1] == '*')
			flag_list.pwidth = va_arg(args, int);
	if (flag_list.point && flag_list.point[1] != '*')
		flag_list.pwidth = ft_atoi(&flag_list.point[1]);
}

static void	width_det(const char *s, va_list args, t_list flag_list, char type)
{
	int	i;

	pwidth_det(const char *s, va_list args, t_list flag_list, char type);
	i = -1;
	while (s[++i] != type)
		if (s[i] == '*' && s[i - 1] != '.')
			flag_list.width = va_arg(args, int);
	flag_list.width_ptr = ft_strnrchr(s, '*', i);
	while (i > -1)
	{
		while (i > -1 && (!ft_isdigit(s[i]) || s[i] == '0'))
			i--;
		while (i > -1 && ft_isdigit(s[i]))
			i--;
		if (i > -1 && s[i] != '.')
			break ;
	}
	if (++i > 0 && &s[i] > flag_list.width_ptr)
		flag_list.width_ptr = &s[i];
	if (i > 0)
		flag_list.width = (ft_atoi(&s[i]));
}

int	printfing(const char *s, va_list args, t_list flag_list, char type)
{
	char	*print;
	int		rt;

	width_det(s, args, flag_list, type);
	print = NULL;
	if (type == 'c')
		print = printf_char(flag_list, va_arg(args, char));
	else if (type == 's')
		print = printf_str(flag_list, va_arg(args, char *));
	else if (type == 'p')
		print = printf_void(flag_list, va_arg(args, void *));
	else if (type == 'd' || type == 'i')
		print = printf_int(flag_list, va_arg(args, int));
	else if (type == 'u')
		print = printf_uint(flag_list, va_arg(args, unsigned int));
	else if (type == 'x' || type == 'X')
		print = printf_hex(flag_list, va_arg(args, unsigned long long), type);
	else if (type == '%')
		print = printf_perc(flag_list);
	if (!print)
		return (0);
	rt = ft_strlen(print);
	write(1, print, rt);
	free(print);
	return (rt);
}
