/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions_2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: swijnber <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/29 18:13:44 by swijnber          #+#    #+#             */
/*   Updated: 2022/10/11 14:10:28 by swijnber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	rotating(int *a)
{
	int	i;
	int	buf;

	if (a[0] < 1 || a[1] < 1)
		return ;
	buf = a[0];
	i = -1;
	while (a[++i + 1] > 0)
		a[i] = a[i + 1];
	a[i] = buf;
}

int	rotate(int *a, int *b, char print, char which)
{
	if (which == 'a')
		rotating(a);
	else if (which == 'b')
		rotating(b);
	else if (which == 'r')
	{
		rotating(a);
		rotating(b);
	}
	if (print == 'y')
		ft_printf("r%c\n", which);
	return (1);
}

static void	rrotating(int *a)
{
	int	i;
	int	buf;

	if (a[0] < 1 || a[1] < 1)
		return ;
	i = 0;
	while (a[i] > 0)
		i++;
	buf = a[--i];
	while (i--)
		a[i + 1] = a[i];
	a[0] = buf;
}

int	rrotate(int *a, int *b, char print, char which)
{
	if (which == 'a')
		rrotating(a);
	else if (which == 'b')
		rrotating(b);
	else if (which == 'r')
	{
		rrotating(a);
		rrotating(b);
	}
	if (print == 'y')
		ft_printf("rr%c\n", which);
	return (1);
}
