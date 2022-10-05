/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions_1.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: swijnber <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/29 18:12:47 by swijnber          #+#    #+#             */
/*   Updated: 2022/10/05 06:56:32 by swijnber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	swapping(int *a, int *a_)
{
	int	buf;

	if ((a[0] < 1 || a[1] < 1))
		return ;
	buf = a[0];
	a[0] = a[1];
	a[1] = buf;
	buf = a_[0];
	a_[0] = a_[1];
	a_[1] = buf;
}

int	swap(t_stacks stacks, char print, char which)
{
	if (which == 'a')
		swapping(stacks.a, stacks.a_);
	else if (which == 'b')
		swapping(stacks.b, stacks.b_);
	else if (which == 's')
	{
		swapping(stacks.a, stacks.a_);
		swapping(stacks.a, stacks.a_);
	}
	if (print == 'y')
		ft_printf("s%c\n", which);
	return (1);
}

static void	pushing(int *a, int *a_, int *b, int *b_)
{
	if (a_[0] < 1)
		return ;
	shift_down(b, b_);
	b[0] = a[0];
	b_[0] = a_[0];
	shift_up(a, a_);
}

int	push(t_stacks stacks, char print, char which)
{
	if (which == 'a')
		pushing(stacks.b, stacks.b_, stacks.a, stacks.a_);
	else if (which == 'b')
		pushing(stacks.a, stacks.a_, stacks.b, stacks.b_);
	if (print == 'y')
		ft_printf("p%c\n", which);
	return (1);
}
