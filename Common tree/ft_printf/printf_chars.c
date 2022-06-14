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
	rt[i] = 0;
	if (lag.minus)
		i += printfill(&rt[i], ' ', lag.width - 1);
	return (rt);
}

static char	*ft_25(t_f lag, char *arg)
{
	char	*s;

	if (!arg)
		s = ft_strdup("(null)");
	else
		s = ft_strdup(arg);
	if (!s)
		return (NULL);
	if (!arg && lag.point && lag.pwidth < 6)
		s[0] = 0;
	else if (lag.point && lag.pwidth < (int)ft_strlen(s))
		s[lag.pwidth] = 0;
	return (s);
}

char	*printf_str(t_f lag, char *arg)
{
	char	*rt;
	char	*s;
	int		len;
	int		i;

	s = ft_25(lag, arg);
	if (!s)
		return (NULL);
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

static char	*ft_25_2(t_f lag, char *rt, char *hex, int nil)
{
	int	len;
	int	i;

	len = ft_strlen(hex);
	i = 0;
	if (!lag.minus && (lag.point || !lag.zero))
		i += printfill(rt, ' ', lag.width - ft_max(lag.pwidth, len) - nil);
	if (nil)
		i += ft_strlcpy(&rt[i], "0x", 3);
	if (nil)
		i += printfill(&rt[i], '0', lag.pwidth - len);
	if (!lag.minus && !lag.point && lag.zero)
		i += printfill(&rt[i], '0', lag.width - ft_max(lag.pwidth, len) - nil);
	i += ft_strlcpy(&rt[i], hex, len + 1);
	if (lag.minus)
		printfill(&rt[i], ' ', lag.width - ft_max(lag.pwidth, len) - nil);
	free(hex);
	return (rt);
}

char	*printf_void(t_f lag, void *arg)
{
	char	*hex;
	char	*rt;
	int		len;
	int		nil;

	if (arg)
		hex = ft_hex_conv((unsigned long long)arg);
	else
		hex = ft_strdup("(nil)");
	if (!hex)
		return (NULL);
	len = ft_strlen(hex);
	nil = 2;
	if (!arg)
		nil = 0;
	if (nil)
		lag.width = ft_max(lag.width, lag.pwidth + nil);
	rt = malloc(sizeof(char) * (ft_max(lag.width, len + nil) + 1));
	if (!rt)
		return (printfree(hex));
	return (ft_25_2(lag, rt, hex, nil));
}
