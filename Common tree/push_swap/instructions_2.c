/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions_2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: swijnber <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/29 18:13:44 by swijnber          #+#    #+#             */
/*   Updated: 2022/09/30 15:57:43 by swijnber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	rotating(int *a, int *a_)
{
	int	i;
	int	buf;
	int	buf_;

	if (a_[0] < 1 || a_[1] < 1)
		return ;
	buf = a[0];
	buf_ = a_[0];
	i = shift_up(a, a_);
	a[i] = buf;
	a_[i] = buf_;
}

int	rotate(t_stacks stacks, char which)
{
	if (which == 'a')
		rotating(stacks.a, stacks.a_);
	else if (which == 'b')
		rotating(stacks.b, stacks.b_);
	else if (which == 'r')
	{
		rotating(stacks.a, stacks.a_);
		rotating(stacks.b, stacks.b_);
	}
	ft_printf("r%c\n", which);
	return (1);
}

static void	rrotating(int *a, int *a_)
{
	int	i;
	int	buf;

	if (a_[0] < 1 || a_[1] < 1)
		return ;
	i = 0;
	while (a_[i] > 0)
		i++;
	buf = a_[i];
	i = shift_down(a, a_);
	a[0] = a[i];
	a_[0] = a_[i];
	a[i] = INT_MAX;
	a_[i] = buf;
}

int	rrotate(t_stacks stacks, char which)
{
	if (which == 'a')
		rrotating(stacks.a, stacks.a_);
	else if (which == 'b')
		rrotating(stacks.b, stacks.b_);
	else if (which == 'r')
	{
		rrotating(stacks.a, stacks.a_);
		rrotating(stacks.b, stacks.b_);
	}
	ft_printf("rr%c\n", which);
	return (1);
}
