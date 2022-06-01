/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_uint.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: swijnber <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/01 13:28:56 by swijnber          #+#    #+#             */
/*   Updated: 2022/06/01 14:02:25 by swijnber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

char	*printf_uint(t_f f_list, unsigned int arg)
{
	char	*nb;
	char	*rt;
	int		len;
	int		i;

	nb = ft_itoa((long)arg);
	if (!nb)
		return (NULL);
	len = ft_strlen(nb);
	f_list.width = ft_max(f_list.width, f_list.pwidth);
	rt = malloc(sizeof(char) * (f_list.width + 1));
	if (!rt)
		return (printfree(nb));
	i = 0;
	if (!f_list.minus && (f_list.point || !f_list.zero))
		i += printfilling(rt, ' ', f_list.width - ft_max(len, f_list.pwidth));
	else if (!f_list.minus && !f_list.point && f_list.zero)
		i += printfilling(rt, '0', f_list.width - ft_max(len, f_list.pwidth));
	i += printfilling(&rt[i], '0', f_list.pwidth - len);
	i += ft_strlcpy(&rt[i], nb, len + 1);
	if (f_list.minus)
		printfilling(&rt[i], ' ', f_list.width - ft_max(len, f_list.pwidth));
	free(nb);
	return (rt);
}
