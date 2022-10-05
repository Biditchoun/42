/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithms_2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: swijnber <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/05 03:08:50 by swijnber          #+#    #+#             */
/*   Updated: 2022/10/05 08:02:29 by swijnber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static t_stacks	sbuf_check(t_stacks stacks, int argc, char print)
{
	t_stacks	sbuf;

	if (print != 'y')
		sbuf = sbuf_init(stacks, argc);
	else
		sbuf = stacks;
	return (sbuf);
}

static char	**instructs_base(void)
{
	char	rt[12][3];

	rt[0] = "sa";
	rt[1] = "sb";
	rt[2] = "ss";
	rt[3] = "pa";
	rt[4] = "pb";
	rt[5] = "ra";
	rt[6] = "rb";
	rt[7] = "rr";
	rt[8] = "oa";
	rt[9] = "ob";
	rt[10] = "or";
	rt[11] = NULL;
	return (rt);
}

static int	check_stacks(t_stacks stacks, int argc)
{
	int	i;

	if (stacks.b_[0] > 0)
		return (1);
	i = -1;
	while (++i < argc)
		if (stacks.a_[i] != i + 1)
			return (1);
	return (0);
}

static int	backtracking_kinda(t_stacks sbuf, int argc, char print)
{

	sbuf = sbuf_check(stacks, --argc, print);
	if (!sbuf.a)
		return (-1);

}

int	algo_4(t_stacks stacks, int argc, char print)
{
	//int			rt;
	char		**base;
	t_stacks	sbuf;

	base = instructs_base(void);
	if (!check_stacks(sbuf, --argc))
		return (0);
	return (1);
}

