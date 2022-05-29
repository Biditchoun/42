/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_char.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: swijnber <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/24 16:58:23 by swijnber          #+#    #+#             */
/*   Updated: 2022/05/29 07:46:09 by swijnber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

static char	*minus(t_f f_list, char *rt, char arg)
{
	int	i;

	i = 0;
	if (arg)
		rt[i++] = arg;
	printfilling(&rt[i], ' ', f_list.width - i);
	rt[f_list.width] = 0;
	return (rt);
}

char	*printf_char(t_f f_list, char arg)
{
	char	*rt;

	if (!f_list.width)
		f_list.width = 1;
	if (!arg)
		f_list.width--;
	rt = malloc(sizeof (char) * (f_list.width + 1));
	if (!rt)
		return (NULL);
	if (f_list.minus)
		return (minus(f_list, rt, arg));
	if (f_list.zero)
		printfilling(rt, '0', f_list.width);
	else
		printfilling(rt, ' ', f_list.width);
	if (!arg)
		rt[f_list.width - 1] = arg;
	rt[f_list.width] = 0;
	return (rt);
}
