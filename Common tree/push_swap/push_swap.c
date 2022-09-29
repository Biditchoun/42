/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: swijnber <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/29 18:14:45 by swijnber          #+#    #+#             */
/*   Updated: 2022/09/29 18:14:53 by swijnber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	error_rt(t_stacks stacks, int argc)
{
	if (argc < 2)
		return (-1);
	write(2, "Error\n", 6);
	if (stacks.a)
		freestacks(stacks);
	return (-1);
}

int	main(int argc, char **argv)
{
	t_stacks	stacks;

	stacks.a = init_stack_a(argc, argv);
	if (!stacks.a)
		return (error_rt(stacks, argc));
	stacks.b = init_stack_b(argc);
	if (!stacks.b)
		return (error_rt(stacks, argc));
	stacks.a_ = init_stack_a_(stacks.a, argc - 1);
	if (!stacks.a_)
		return (error_rt(stacks, argc));
	stacks.b_ = init_stack_b_(stacks.a_, argc);
	if (!stacks.b_)
		return (error_rt(stacks, argc));
	algorithms_hq(stacks, argc);
	return (0);
}
