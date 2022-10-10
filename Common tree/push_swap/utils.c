/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: swijnber <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/29 18:15:43 by swijnber          #+#    #+#             */
/*   Updated: 2022/10/10 00:01:14 by swijnber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	printstacks(t_stacks stacks, int argc)
{
	int	i;

	i = 0;
	ft_printf("Stack a:\n");
	while (i < argc - 1)
		ft_printf("%i ", stacks.a[i++]);
	ft_printf("\n");
	i = 0;
	while (i < argc)
		ft_printf("%i ", stacks.a_[i++]);
	ft_printf("\nStack b:\n");
	i = 0;
	while (i < argc - 1)
		ft_printf("%i ", stacks.b[i++]);
	ft_printf("\n");
	i = 0;
	while (i < argc)
		ft_printf("%i ", stacks.b_[i++]);
	ft_printf("\n\n");
}

void	*freestacks(t_stacks stacks)
{
	if (stacks.a)
		free(stacks.a);
	if (stacks.a_)
		free(stacks.a_);
	if (stacks.b)
		free(stacks.b);
	if (stacks.b_)
		free(stacks.b_);
	return (NULL);
}

void	shift_down(int *a, int *a_, int i)
{
	while (i)
	{
		a[i] = a[i - 1];
		a_[i] = a_[i - 1];
		i--;
	}
}

int	shift_up(int *a, int *a_)
{
	int	i;

	if (a_[0] < 1)
		return (0);
	i = -1;
	while (a_[++i + 1] > 0)
	{
		a[i] = a[i + 1];
		a_[i] = a_[i + 1];
	}
	a[i] = INT_MAX;
	a_[i] = a_[i + 1];
	return (i);
}

int	arrchr(int *a, int n)
{
	int	i;

	i = 0;
	while (a[i] != n)
		i++;
	return (i);
}
