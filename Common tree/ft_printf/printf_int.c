/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_int.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: swijnber <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/31 10:24:16 by swijnber          #+#    #+#             */
/*   Updated: 2022/05/31 12:28:14 by swijnber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

char	*printf_int(t_f f_list, int arg)
{
	char	*nb;
	char	*rt;
	int		len;
	int		sign;
	int		i;

	nb = ft_itoa(arg);
	if (!nb)
		return (NULL);
	len = ft_strlen(nb);
	sign = 0;
	if ((f_list.plus || f_list.space) && arg > -1)
		sign++;
	if (f_list.pwidth + sign > f_list.width)
		f_list.width = f_list.pwidth + sign;
	rt = malloc(sizeof(char) * (ft_max(f_list.width, len + sign) + 1));
	if (!rt)
		return (printfree(nb));
	if (f_list.minus)
		return (minus(rt, f_list, nb, len, sign));
	if (f_list.point)
		return (point(rt, f_list, nb, len, sign));
	i = 0;
	if (!f_list.zero || f_list.point)
		i += printfilling(&rt[i], ' ', f_list.width - f_list.pwidth - len - sign);
	if (f_list.plus && nb > -1)
		rt[i++] = '+';
	else if (f_list.space && nb > -1)
		rt[i++] = ' ';
	if (f_list.zero)
		i += printfilling(&rt[i], '0', f_list.width - len - sign);
	i += ft_strlcpy(&rt[i], nb, len + 1);
	free(nb);
	return (rt);
}
