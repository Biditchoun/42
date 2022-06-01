/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_int.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: swijnber <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/31 10:24:16 by swijnber          #+#    #+#             */
/*   Updated: 2022/06/01 13:34:44 by swijnber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

static char	*minus(t_f f_list, char *rt, char *nb, int sign)
{
	int	i;
	int	sign;

	sign = 0;
	if ((f_list.plus || f_list.space) && arg > -1)
		sign++;
	i = 0;
	if (nb[0] == '-')
		rt[i++] = '-';
	else if (f_list.plus)
		rt[i++] = '+';
	else if (f_list.space)
		rt[i++] = ' ';
	if (f_list.point)
		i += printfilling(&rt[i], '0', f_list.pwidth - len);
	if (nb[0] != '-')
		i += ft_strlcpy(&rt[i], nb, len + 1);
	else
		i += ft_strlcpy(&rt[i], &nb[1], len);
	i += printfilling(&rt[i], ' ',
			f_list.width - ft_max(f_list.pwidth, len) - sign);
	return (rt);
}

static char	*ft_25(t_f f_list, char *rt, char *nb, int sign)
{
	int	i;
	int	sign;

	sign = 0;
	if ((f_list.plus || f_list.space) && arg > -1)
		sign++;
	i = 0;
	if (!f_list.zero || f_list.point)
		i += printfilling(rt, ' ',
				f_list.width - ft_max(f_list.pwidth, len) - sign);
	if (nb[0] == '-')
		rt[i++] = '-';
	else if (f_list.plus)
		rt[i++] = '+';
	else if (f_list.space)
		rt[i++] = ' ';
	if (f_list.point)
		i += printfilling(&rt[i], '0', f_list.pwidth - len);
	else if (f_list.zero)
		i += printfilling(&rt[i], '0', f_list.width - len - sign);
	if (nb[0] != '-')
		i += ft_strlcpy(&rt[i], nb, len + 1);
	else
		i += ft_strlcpy(&rt[i], &nb[1], len);
	return (rt);
}

char	*printf_int(t_f f_list, int arg)
{
	char	*nb;
	char	*rt;
	int		len;
	int		sign;

	nb = ft_itoa((long)arg);
	if (!nb)
		return (NULL);
	len = ft_strlen(nb);
	sign = 0;
	if ((f_list.plus || f_list.space) && arg > -1)
		sign++;
	else if (arg < 0)
		f_list.pwidth++;
	f_list.width = ft_max(f_list.width, f_list.pwidth + sign);
	rt = malloc(sizeof(char) * (ft_max(f_list.width, len + sign) + 1));
	if (!rt)
		return (printfree(nb));
	if (f_list.minus)
		rt = minus(rt, f_list, nb, len);
	else
		rt = ft_25(f_list, rt, nb, sign);
	free(nb);
	return (rt);
}
