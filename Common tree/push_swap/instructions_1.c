/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions_1.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: swijnber <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/29 18:12:47 by swijnber          #+#    #+#             */
/*   Updated: 2022/10/11 15:19:23 by swijnber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	swapping(int *a)
{
	int	buf;

	if ((a[0] < 1 || a[1] < 1))
		return ;
	buf = a[0];
	a[0] = a[1];
	a[1] = buf;
}

int	swap(int *a, int *b, char print, char which)
{
	if (which == 'a')
		swapping(a);
	else if (which == 'b')
		swapping(b);
	else if (which == 's')
	{
		swapping(a);
		swapping(b);
	}
	if (print == 'y')
		ft_printf("s%c\n", which);
	return (1);
}

static void	pushing(int *a, int *b)
{
	int	i;

	if (a[0] < 1)
		return ;
	i = 0;
	while (b[i] > 0)
		i++;
	b[i + 1] = b[i];
	while (i--)
		b[i + 1] = b[i];
	b[0] = a[0];
	while (a[++i] > 0)
		a[i] = a[i + 1];
}

int	push(int *a, int *b, char print, char which)
{
	if (which == 'b')
		pushing(a, b);
	else if (which == 'a')
		pushing(b, a);
	if (print == 'y')
		ft_printf("p%c\n", which);
	return (1);
}
