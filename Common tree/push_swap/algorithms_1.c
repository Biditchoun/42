/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithms_1.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: swijnber <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/29 18:11:41 by swijnber          #+#    #+#             */
/*   Updated: 2022/09/30 18:54:36 by swijnber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	algo_1(t_stacks stacks, int argc)
{
	if (argc > 4)
		return ;
	argc--;
	if (stacks.a_[0] == argc)
		rotate(stacks, 'a');
	else if (stacks.a_[1] == argc && argc == 3)
		rrotate(stacks, 'a');
	if (stacks.a_[0] != 1)
		swap(stacks, 'a');
}

static void	algo_2_1(t_stacks stacks)
{
	if (stacks.a_[1] == 4)
		give_instructions(stacks, 2, "ra", "ra");
	else if (stacks.a_[2] == 4)
		give_instructions(stacks, 2, "sa", "oa");
	else if (stacks.a_[3] == 4)
		give_instructions(stacks, 4, "oa", "sa", "ra", "ra");
}

static void	algo_2_2(t_stacks stacks)
{
	if (stacks.a_[0] == 4)
		give_instructions(stacks, 3, "oa", "sa", "ra");
	else if (stacks.a_[1] == 4 && stacks.a_[0] == 1)
		give_instructions(stacks, 4, "pb", "sa", "oa", "pa");
	else if (stacks.a_[1] == 4)
		give_instructions(stacks, 4, "ra", "sa", "ra", "ra");
}

static void	algo_2_3(t_stacks stacks)
{
	if (stacks.a_[0] == 4)
		rotate(stacks, 'a');
	else if (stacks.a_[1] == 4)
		give_instructions(stacks, 2, "sa", "ra");
	else if (stacks.a_[2] == 4)
		give_instructions(stacks, 4, "pb", "sa", "ra", "pa");
}

void	algo_2(t_stacks stacks, int argc)
{
	if (argc != 5)
		return ;
	argc--;
	if (stacks.a_[0] > stacks.a_[1] && (stacks.a_[0] != 4 || (stacks.a_[0] == 4 && stacks.a_[1] == 3)))
		swap(stacks, 'a');
	if (stacks.a_[0] == 3)
		algo_2_1(stacks);
	else if (stacks.a_[1] == 3)
	{
		if (stacks.a_[2] == 4)
			rrotate(stacks, 'a');
		else if (stacks.a_[3] == 4)
			give_instructions(stacks, 3, "ra", "sa", "oa");
	}
	else if (stacks.a_[2] == 3)
		algo_2_2(stacks);
	else if (stacks.a_[3] == 3)
		algo_2_3(stacks);
	if (stacks.a_[0] != 1)
		swap(stacks, 'a');
}
