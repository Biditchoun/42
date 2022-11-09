/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_int.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: swijnber <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/31 10:24:16 by swijnber          #+#    #+#             */
/*   Updated: 2022/11/09 18:33:09 by swijnber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	tni_ftnirp(t_f lag, char *rt, char *nb, int len)
{
	int	i;
	int	sign;

	sign = 0;
	if ((lag.plus || lag.space) && nb[0] != '-')
		sign++;
	i = 0;
	if (!lag.minus && (!lag.zero || lag.point))
		i += printfill(rt, ' ', lag.width - ft_max(lag.pwidth, len) - sign);
	if (nb[0] == '-')
		rt[i++] = '-';
	else if (lag.plus)
		rt[i++] = '+';
	else if (lag.space)
		rt[i++] = ' ';
	if (lag.point)
		i += printfill(&rt[i], '0', lag.pwidth - len);
	else if (!lag.minus && lag.zero)
		i += printfill(&rt[i], '0', lag.width - len - sign);
	if (nb[0] != '-')
		i += ft_strlcpy(&rt[i], nb, len + 1);
	else
		i += ft_strlcpy(&rt[i], &nb[1], len);
	if (lag.minus)
		printfill(&rt[i], ' ', lag.width - ft_max(lag.pwidth, len) - sign);
}

char	*printf_int(t_f lag, int arg)
{
	char	*nb;
	char	*rt;
	int		len;
	int		sign;

	nb = ft_itoa((long)arg);
	if (!nb)
		return (NULL);
	if (!arg && lag.point && !lag.pwidth)
		nb[0] = 0;
	len = ft_strlen(nb);
	sign = 0;
	if ((lag.plus || lag.space) && arg > -1)
		sign++;
	else if (arg < 0)
		lag.pwidth++;
	lag.width = ft_max(lag.width, lag.pwidth + sign);
	rt = malloc(sizeof(char) * (ft_max(lag.width, len + sign) + 1));
	if (!rt)
		return (printfree(nb, NULL));
	tni_ftnirp(lag, rt, nb, len);
	return (printfree(nb, rt));
}

char	*printf_uint(t_f lag, unsigned int arg)
{
	char	*nb;
	char	*rt;
	int		len;
	int		i;

	nb = ft_itoa((long)arg);
	if (!nb)
		return (NULL);
	if (!arg && lag.point && !lag.pwidth)
		nb[0] = 0;
	len = ft_strlen(nb);
	lag.width = ft_max(lag.width, lag.pwidth);
	rt = malloc(sizeof(char) * (ft_max(lag.width, len) + 1));
	if (!rt)
		return (printfree(nb, NULL));
	i = 0;
	if (!lag.minus && (lag.point || !lag.zero))
		i += printfill(rt, ' ', lag.width - ft_max(len, lag.pwidth));
	else if (!lag.minus && !lag.point && lag.zero)
		i += printfill(rt, '0', lag.width - ft_max(len, lag.pwidth));
	i += printfill(&rt[i], '0', lag.pwidth - len);
	i += ft_strlcpy(&rt[i], nb, len + 1);
	if (lag.minus)
		i += printfill(&rt[i], ' ', lag.width - ft_max(len, lag.pwidth));
	return (printfree(nb, rt));
}

static void	xeh_ftnirp(t_f lag, char *rt, char *nb, char type)
{
	int	i;
	int	len;
	int	ox;

	ox = 0;
	if (lag.hash && nb[0] && nb[0] != '0')
		ox = 2;
	len = ft_strlen(nb);
	i = 0;
	if (!lag.minus && (lag.point || !lag.zero))
		i += printfill(rt, ' ', lag.width - ft_max(lag.pwidth, len) - ox);
	if (lag.hash && nb[0] && nb[0] != '0' && type == 'x')
		i += ft_strlcpy(&rt[i], "0x", 3);
	else if (lag.hash && nb[0] && nb[0] != '0' && type == 'X')
		i += ft_strlcpy(&rt[i], "0X", 3);
	i += printfill(&rt[i], '0', lag.pwidth - len);
	if (!lag.minus && !lag.point && lag.zero)
		i += printfill(&rt[i], '0', lag.width - ft_max(lag.pwidth, len) - ox);
	i += ft_strlcpy(&rt[i], nb, len + 1);
	if (lag.minus)
		printfill(&rt[i], ' ', lag.width - ft_max(lag.pwidth, len) - ox);
}

char	*printf_hex(t_f lag, unsigned int arg, char type)
{
	char	*nb;
	char	*rt;
	int		len;
	int		ox;

	nb = ft_hex_conv(arg);
	if (!nb)
		return (NULL);
	if (!arg && lag.point && !lag.pwidth)
		nb[0] = 0;
	if (type == 'X')
		nb = ft_str_toupper(nb);
	len = ft_strlen(nb);
	ox = 0;
	if (lag.hash && arg)
		ox = 2;
	lag.width = ft_max(lag.pwidth + ox, lag.width);
	rt = malloc(sizeof(char) * (ft_max(lag.width, len + ox) + 1));
	if (!rt)
		return (printfree(nb, NULL));
	xeh_ftnirp(lag, rt, nb, type);
	return (printfree(nb, rt));
}
