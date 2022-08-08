/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: swijnber <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/16 14:02:17 by swijnber          #+#    #+#             */
/*   Updated: 2022/08/08 16:28:26 by swijnber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

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
			if (!ft_isdigit(*(zero - i)) && *(zero - i) != '.')
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
	int		*parsrt;
	t_f		lag;

	parsrt = malloc(sizeof(int) * 2);
	if (!parsrt)
		return (NULL);
	flags = "0123456789-+# .*";
	i = 1;
	while (ft_strchr(flags, s[i]) && s[i])
		i++;
	type = s[i];
	parsrt[0] = i;
	lag = flags_addresses(s, i);
	if (!s[i])
		parsrt[1] = -2;
	else
		parsrt[1] = printfing(&s[1], args, lag, type) - 1;
	return (parsrt);
}

static int	ftnirp_tf(const char *s, va_list args)
{
	int	i;
	int	rt;
	int	*parsrt;

	rt = 0;
	i = 0;
	while (s[i])
	{
		if (s[i++] != '%')
			write(1, &s[i - 1], 1);
		else
		{
			parsrt = parsing(&s[i - 1], args);
			if (!parsrt)
				break ;
			i += parsrt[0];
			rt += parsrt[1];
			if (parsrt[1] < -1)
				return (printfreez(parsrt, rt + 1));
			free(parsrt);
		}
		rt++;
	}
	return (rt);
}

int	ft_printf(const char *s, ...)
{
	int		rt;
	va_list	args;

	if (!s)
		return (0);
	va_start(args, s);
	rt = ftnirp_tf(s, args);
	va_end(args);
	return (rt);
}
