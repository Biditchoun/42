/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_void.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: swijnber <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/26 20:05:32 by swijnber          #+#    #+#             */
/*   Updated: 2022/05/29 08:30:40 by swijnber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

static char	*minus(char *rt, t_f f_list, char *hex, int len)
{
	int		i;

	i = 0;
	i += ft_strlcpy(rt, "0x", 3);
	if (f_list.pwidth > len)
		i += printfilling(&rt[i], '0', f_list.pwidth - len);
	i += ft_strlcpy(&rt[i], hex, len + 1);
	if (f_list.width > i)
		i += printfilling(&rt[i], ' ', f_list.width - i);
	rt[i] = 0;
	free(hex);
	return (rt);
}

char	*printf_void(t_f f_list, void *arg)
{
	char	*hex;
	char	*rt;
	int		len;
	int		i;

	hex = ft_hex_conv((unsigned long long)arg);
	if (!hex)
		return (NULL);
	len = ft_strlen(hex);
	if (f_list.point > f_list.width_ptr && f_list.pwidth + 2 > f_list.width)
		f_list.width = f_list.pwidth + 2;
	rt = malloc(sizeof(char) * (ft_max(f_list.width, len + 2) + 1));
	if (!rt)
		return (printfree(hex));
	if (f_list.minus)
		return (minus(t_f f_list, hex, len));
	i = 0;
	if ((!f_list.point || !f_list.zero) && f_list.width > f_list.pwidth + 2)
		i += printfilling(rt, ' ', f_list.width - f_list.pwidth - 2);
	i += ft_strlcpy(&rt[i], "0x", 3);
	if ((!f_list.point && f_list.zero) || f_list.point)
		i += printfilling(&rt[i], '0', f_list.pwidth - len);
	ft_strlcpy(&rt[i], hex, len + 1);
	free(hex);
	return (rt);
}
