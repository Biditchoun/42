/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithms_2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: swijnber <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/05 03:08:50 by swijnber          #+#    #+#             */
/*   Updated: 2022/10/06 15:29:11 by swijnber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static char	**instructs_base(void)
{
	char	**rt;

	rt = malloc(sizeof(char *) * 12);
	if (!rt)
		return (NULL);
	rt[0] = "sa";
	rt[1] = "ra";
	rt[2] = "oa";
	rt[3] = "pb";
	rt[4] = "sb";
	rt[5] = "ss";
	rt[6] = "rb";
	rt[7] = "rr";
	rt[8] = "ob";
	rt[9] = "or";
	rt[10] = "pa";
	rt[11] = NULL;
	return (rt);
}

/*static int	first_checks(int *instructs)
{
	//int	i;

	if (instructs[1] > 3)
	{
		instructs[0]++;
		instructs[1] = 0;
	}
	if (instructs[0] > 3)
		instructs[0] = 11;
	if (instructs[0] > 3)
		return (0);
	return (1);
}*/

static int	check_insts(t_stacks stacks, int argc, int *instructs, char print)
{
	char		**base;
	int			i;
	t_stacks	sbuf;

	//if (!first_checks(instructs))
	//	return (0);
	sbuf = sbuf_init(stacks, argc);
	if (!sbuf.a)
		return (-1);
	base = instructs_base();
	if (!base)
		return ((int)freestacks(sbuf) - 1);
	i = 0;
	while (instructs[i] != -1)
		give_instructs(sbuf, print, 1, base[instructs[i++]]);
	free(base);
	if (sbuf.b_[0] > 0)
		return ((int)freestacks(sbuf));
	i = -1;
	while (++i < argc - 1)
		if (sbuf.a_[i] != i + 1)
			return ((int)freestacks(sbuf));
	freestacks(sbuf);
	return (1);
}

static int	fill_instructs(int *instructs, int count)
{
	int	i;

	i = count - 1;
	while (i > -1 && instructs[i] == 10)
		i--;
	if (i > -1)
	{
		instructs[i]++;
		while (++i < count)
			instructs[i] = 0;
		return (0);
	}
	else
	{
		i = -1;
		while (++i < count + 1)
			instructs[i] = 0;
		instructs[i] = -1;
		return (1);
	}
}

int	algo_4(t_stacks stacks, int argc)
{
	int		instructs[100];
	int		count;

	instructs[0] = -1;
	if (check_insts(stacks, argc, instructs, 'n') > 0)
		return (0);
	count = 0;
	while (count < 100)
	{
		count += fill_instructs(instructs, count);
		ft_printf("%i | %i %i %i %i %i %i\n", count, instructs[0], instructs[1], instructs[2], instructs[3], instructs[4]);
		if (check_insts(stacks, argc, instructs, 'n') > 0)
			break ;
	}
	if (count == 100)
		return (INT_MAX);
	check_insts(stacks, argc, instructs, 'y');
	return (count);
}
