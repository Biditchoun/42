/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithms_1.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: swijnber <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/07 23:44:09 by swijnber          #+#    #+#             */
/*   Updated: 2022/10/11 15:18:52 by swijnber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static t_brute	force_init(int *a, int *instructs, int argc)
{
	t_brute	rt;

	rt.base = malloc(sizeof(char *) * 12);
	if (!rt.base)
		return (rt);
	rt.base[0] = "sa";
	rt.base[1] = "ra";
	rt.base[2] = "oa";
	rt.base[3] = "pb";
	rt.base[4] = "pa";
	rt.base[5] = "sb";
	rt.base[6] = "ss";
	rt.base[7] = "rb";
	rt.base[8] = "rr";
	rt.base[9] = "ob";
	rt.base[10] = "or";
	rt.base[11] = NULL;
	rt.a = a;
	rt.instructs = instructs;
	rt.argc = argc;
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

static int	check_instructs(t_brute force, char print)
{
	int	i;
	int	*a_;
	int	*b_;

	if (instructs_check(force.instructs))
		return (0);
	a_ = ft_arrcp(force.a, force.argc);
	if (!a_)
		return (-1);
	b_ = malloc(sizeof(int) * force.argc);
	if (!b_)
		return ((int)ft_free((void *)a_, NULL) - 1);
	b_[0] = a_[force.argc];
	i = 0;
	print_arr(force.instructs);
	while (force.instructs[i] != -1)
		give_instructs(a_, b_,  print, 1, force.base[force.instructs[i++]]);
	i = -1;
	while (++i < force.argc - 1)
		if (a_[i] != i + 1)
			return ((int)ft_free2((void *)a_, (void *)b_, NULL));
	free(a_);
	free(b_);
	return (1);
}

int	brute_force(int *a_, int argc)
{
	int		instructs[15];
	int		count;
	t_brute	force;
	int		safe;

	instructs[0] = -1;
	force = force_init(a_, instructs, argc);
	if (!force.base)
		return (-1);
	count = 0;
	while (count < 15)
	{
		count += fill_instructs(instructs, count);
		safe = check_instructs(force, 'n');
		if (safe == -1)
			return ((int)ft_free((void *)force.base, NULL) - 1);
		else if (safe)
			break ;
	}
	if (count == 15)
		return (INT_MAX);
	check_instructs(force, 'y');
	free(force.base);
	return (count);
}
