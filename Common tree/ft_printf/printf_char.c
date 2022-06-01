/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_char.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: swijnber <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/24 16:58:23 by swijnber          #+#    #+#             */
/*   Updated: 2022/06/01 14:02:15 by swijnber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

char	*printf_char(t_f f_list, char arg)
{
	char	*rt;
	int		i;

	if (!arg && f_list.width)
		f_list.width--;
	rt = malloc(sizeof (char) * (f_list.width + 1));
	if (!rt)
		return (NULL);
	i = 0;
	if (!f_list.minus && f_list.zero)
		i += printfilling(rt, '0', f_list.width - 1);
	else if (!f_list.minus)
		i += printfilling(rt, ' ', f_list.width - 1);
	if (!arg)
		rt[i++] = arg;
	if (f_list.minus)
		i += printfilling(&rt[i], ' ', f_list.width - 1);
	rt[i] = 0;
	return (rt);
}
