/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithms_1.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: swijnber <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/29 18:11:41 by swijnber          #+#    #+#             */
/*   Updated: 2023/01/17 16:16:53 by swijnber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	algo_1_2(int *a, char print)
{
	int	rt;

	rt = 0;
	if (a[0] > ft_max(a[1], a[2]))
		rt += rotate(a, NULL, print, 'a');
	else if (a[1] > ft_max(a[0], a[2]))
		rt += rrotate(a, NULL, print, 'a');
	if (a[0] > a[1])
		rt += swap(a, NULL, print, 'a');
	return (rt);
}

static int	algo_1_1(int *a, int *b, int argc, char print)
{
	int	i;
	int	count;
	int	rt;

	count = 1;
	rt = 0;
	while (a[3] > 0)
	{
		if (a[0] > a[1])
			rt += swap(a, b, print, 'a');
		i = 0;
		while (a[i] != count)
			i++;
		if (i < argc / 2 + 1)
			while (a[0] != count)
				rt += rotate(a, b, print, 'a');
		else
			while (a[0] != count)
				rt += rrotate(a, b, print, 'a');
		rt += push(a, b, print, 'b');
		count++;
	}
	return (rt);
}

int	algo_1(int *a, int argc, char print)
{
	int	rt;
	int	*a_;
	int	*b_;

	a_ = ft_arrcp(a, argc);
	if (!a_)
		return (-1);
	b_ = malloc(sizeof(int) * argc);
	if (!b_)
		return ((int)ft_free((void *)a_, NULL) - 1);
	rt = 0;
	rt += algo_1_1(a_, b_, argc - 1, print);
	rt += algo_1_2(a_, print);
	while (b_[0] > 0)
		rt += push(a_, b_, print, 'a');
	free(a_);
	free(b_);
	return (rt);
}
