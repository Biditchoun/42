/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithms_1.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: swijnber <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/29 18:11:41 by swijnber          #+#    #+#             */
/*   Updated: 2022/10/08 00:11:37 by swijnber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	algo_2_2(t_stacks stacks, int argc, char print)
{
	int	rt;

	rt = 0;
	if (argc > 4)
		return (-1);
	argc--;
	rt = 0;
	if (stacks.a_[0] > ft_max(stacks.a_[1], stacks.a_[2]))
		rt += rotate(stacks, print, 'a');
	else if (stacks.a_[1] > ft_max(stacks.a_[0], stacks.a_[2]) && argc == 3)
		rt += rrotate(stacks, print, 'a');
	if (stacks.a_[0] > stacks.a_[1])
		rt += swap(stacks, print, 'a');
	return (rt);
}

static int	algo_2_1(t_stacks sbuf, int argc, char print, int rt)
{
	int	i;
	int	count;

	count = 1;
	while (sbuf.a_[3] > 0)
	{
		if (sbuf.a_[0] > sbuf.a_[1])
			rt += swap(sbuf, print, 'a');
		i = 0;
		while (sbuf.a_[i] != count)
			i++;
		if (i < argc / 2 + 1)
			while (sbuf.a_[0] != count)
				rt += rotate(sbuf, print, 'a');
		else
			while (sbuf.a_[0] != count)
				rt += rrotate(sbuf, print, 'a');
		rt += push(sbuf, print, 'b');
		count++;
	}
	return (rt);
}

int	algo_2(t_stacks stacks, int argc, char print)
{
	int			rt;
	t_stacks	sbuf;

	sbuf = sbuf_init(stacks, argc);
	if (!sbuf.a)
		return (-1);
	argc--;
	rt = 0;
	rt += algo_2_1(sbuf, argc, print, rt);
	rt += algo_2_2(sbuf, 4, print);
	while (sbuf.b_[0] > 0)
		rt += push(sbuf, print, 'a');
	freestacks(sbuf);
	return (rt);
}
