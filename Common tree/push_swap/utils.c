/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: swijnber <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/29 18:15:43 by swijnber          #+#    #+#             */
/*   Updated: 2022/09/29 18:16:54 by swijnber         ###   ########.fr       */
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

int	shift_down(int *a, int *a_)
{
	int	i;
	int	rt;

	i = 0;
	while (a_[i] > 0)
		i++;
	rt = i;
	while (i)
	{
		a[i] = a[i - 1];
		a_[i] = a_[i - 1];
		i--;
	}
	return (rt);
}

int	shift_up(int *a, int *a_)
{
	int	i;

	i = 0;
	while (a_[++i] > 0)
	{
		a[i - 1] = a[i];
		a_[i - 1] = a_[i];
	}
	a[--i] = INT_MAX;
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
