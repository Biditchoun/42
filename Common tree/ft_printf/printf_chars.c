/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_char.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: swijnber <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/24 16:58:23 by swijnber          #+#    #+#             */
/*   Updated: 2022/06/03 18:05:48 by swijnber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*printf_char(t_f lag, char arg)
{
	char	*rt;
	int		i;

	lag.width = ft_max(lag.width, 1);
	if (!arg)
		lag.width--;
	rt = malloc(sizeof (char) * (lag.width + 1));
	if (!rt)
		return (NULL);
	i = 0;
	if (!lag.minus && lag.zero)
		i += printfill(rt, '0', lag.width - 1);
	else if (!lag.minus)
		i += printfill(rt, ' ', lag.width - 1);
	if (arg)
		rt[i++] = arg;
	if (lag.minus)
		i += printfill(&rt[i], ' ', lag.width - 1);
	return (rt);
}

char	*printf_str(t_f lag, char *arg)
{
	char	*rt;
	char	*s;
	int		len;
	int		i;

	s = ft_strdup(arg);
	if (!s)
		return (NULL);
	if (lag.point && (int)ft_strlen(s) > lag.pwidth)
		s[lag.pwidth] = 0;
	len = ft_strlen(s);
	rt = malloc(sizeof (char) * (ft_max(lag.width, len) + 1));
	if (!rt)
		return (printfree(s));
	i = 0;
	if (!lag.minus && lag.zero)
		i += printfill(rt, '0', lag.width - len);
	else if (!lag.minus)
		i += printfill(rt, ' ', lag.width - len);
	i += ft_strlcpy(&rt[i], s, len + 1);
	if (lag.minus)
		i += printfill(&rt[i], ' ', lag.width - len);
	free(s);
	return (rt);
}

char	*printf_void(t_f lag, void *arg)
{
	char	*hex;
	char	*rt;
	int		len;
	int		i;

	hex = ft_hex_conv((unsigned long long)arg);
	if (!hex)
		return (NULL);
	len = ft_strlen(hex);
	lag.width = ft_max(lag.width, lag.pwidth + 2);
	rt = malloc(sizeof(char) * (ft_max(lag.width, len + 2) + 1));
	if (!rt)
		return (printfree(hex));
	i = 0;
	if (!lag.minus && (lag.point || !lag.zero))
		i += printfill(rt, ' ', lag.width - ft_max(lag.pwidth, len) - 2);
	i += ft_strlcpy(&rt[i], "0x", 3);
	i += printfill(&rt[i], '0', lag.pwidth - len);
	if (!lag.minus && !lag.point && lag.zero)
		i += printfill(&rt[i], '0', lag.width - ft_max(lag.pwidth, len) - 2);
	i += ft_strlcpy(&rt[i], hex, len + 1);
	if (lag.minus)
		printfill(&rt[i], ' ', lag.width - ft_max(lag.pwidth, len) - 2);
	free(hex);
	return (rt);
}
