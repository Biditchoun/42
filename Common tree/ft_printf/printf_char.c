/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_char.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: swijnber <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/24 16:58:23 by swijnber          #+#    #+#             */
/*   Updated: 2022/05/25 22:02:47 by swijnber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

static void	filling(char *str, char c, int n)
{
	while (n > -1)
		str[n--] = c;
}

char	*printf_char(t_list flag_list, char arg)
{
	char	*rt;

	if (!flag_list.width)
		flag_list.width = 1;
	rt = malloc(sizeof (char) * (flag_list.width + 1));
	if (!rt)
		return (NULL);
	if (flag_list.minus)
	{
		rt[0] = arg;
		filling(&rt[1], ' ', flag_list.width - 1);
		rt[flag_list.width + 1] = 0;
		return (rt);
	}
	if (flag_list.zero)
		filling(rt, '0', flag_list.width - 1);
	else
		filling(rt, ' ', flag_list.width - 1);
	rt[flag_list.width] = arg;
	rt[flag_list.width + 1] = 0;
	return (rt);
}
