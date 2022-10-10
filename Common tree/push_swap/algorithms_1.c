/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithms_1.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: swijnber <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/07 23:44:09 by swijnber          #+#    #+#             */
/*   Updated: 2022/10/10 06:31:09 by swijnber         ###   ########.fr       */
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
	rt[4] = "pa";
	rt[5] = "sb";
	rt[6] = "ss";
	rt[7] = "rb";
	rt[8] = "rr";
	rt[9] = "ob";
	rt[10] = "or";
	rt[11] = NULL;
	return (rt);
}
static void	print_arr(int *arr)
{
	int i = 0;
	while (arr[i] != -1)
		ft_printf("%i ", arr[i++]);
	ft_printf("%i", arr[i]);
	ft_printf("\n");
}
static int	check_insts(t_stacks stacks, int argc, int *instructs, char print)
{
	char		**base;
	int			i;
	t_stacks	sbuf;

	if (instructs_check(instructs))
		return (0);
	sbuf = sbuf_init(stacks, argc);
	if (!sbuf.a)
		return (-1);
	base = instructs_base();
	if (!base)
		return ((int)freestacks(sbuf) - 1);
	print_arr(instructs);
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

int	algo_1(t_stacks stacks, int argc)
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
		if (check_insts(stacks, argc, instructs, 'n') > 0)
			break ;
	}
	if (count == 100)
		return (INT_MAX);
	check_insts(stacks, argc, instructs, 'y');
	return (count);
}
