/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: swijnber <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/29 18:14:45 by swijnber          #+#    #+#             */
/*   Updated: 2022/10/11 14:15:13 by swijnber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	error_rt(int *a, int argc)
{
	if (argc < 2)
		return (-1);
	write(2, "Error\n", 6);
	if (a)
		free(a);
	return (-1);
}

static int	check_order(int *a, int argc)
{
	int	i;

	i = -1;
	while (++i < argc - 1)
		if (a[i] != i + 1)
			return (0);
	return (1);
}

int	main(int argc, char **argv)
{
	int	*a;
	int	*a_;
	int	count;

	a = init_a(argc, argv);
	if (!a)
		return (error_rt(NULL, argc));
	a_ = init_a_(a, argc);
	if (!a_)
		return (error_rt(a, argc));
	free(a);
	if (check_order(a_, argc))
		return ((int)ft_free((void *)a_, NULL));
	count = algorithms_hq(a_, argc);
	if (count < 0)
		return (error_rt(a_, argc));
	return (count);
}
