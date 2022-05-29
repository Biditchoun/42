/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: swijnber <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/16 14:02:17 by swijnber          #+#    #+#             */
/*   Updated: 2022/05/29 08:29:31 by swijnber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

static char	*zero_address(const char *s, int lim)
{
	int		i;
	char	*zero;

	i = 0;
	while (i <= lim)
	{
		zero = ft_strnrchr(s, '0', lim - i);
		if (zero)
		{
			while (*(zero - i) == '0')
				i++;
			if (!ft_isdigit(*(zero - i) || *(zero - i) != '.'))
				break ;
		}
		else
			break ;
	}
	return (zero);
}

static t_f	flags_addresses(const char *s, int lim)
{
	t_f	rt;

	rt.minus = ft_strnrchr(s, '-', lim);
	rt.zero = zero_address(s, lim);
	rt.point = ft_strnrchr(s, '.', lim);
	rt.hash = ft_strnrchr(s, '#', lim);
	rt.space = ft_strnrchr(s, ' ', lim);
	rt.plus = ft_strnrchr(s, '+', lim);
	rt.width_ptr = NULL;
	rt.pwidth = 0;
	rt.width = 0;
	return (rt);
}

static int	*parsing(const char *s, va_list args)
{
	char	*flags;
	char	type;
	int		i;
	int		parsrt[2];
	t_f		flag_list;

	flags = "0123456789-+# .*";
	i = 0;
	while (ft_strchr(flags, s[i]))
		i++;
	type = s[i];
	parsrt[0] = i;
	flag_list = flags_addresses(s, i);
	parsrt[1] = printfing(s, args, flag_list, type);
	return (parsrt);
}

int	ft_printf(const char *s, ...)
{
	int		i;
	int		rt;
	int		*parsrt;
	va_list	args;

	if (!s)
		return (0);
	va_start(args, s);
	rt = 0;
	i = 0;
	while (s[i])
	{
		if (s[i++] != '%')
			write(1, &s[i - 1], 1);
		else
		{
			parsrt = parsing(&s[i], args);
			i += parsrt[0];
			rt += parsrt[1] - 1;
		}
		rt++;
	}
	va_end(args);
	return (rt);
}
