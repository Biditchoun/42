/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithms_hq.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: swijnber <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/29 18:11:53 by swijnber          #+#    #+#             */
/*   Updated: 2022/10/11 08:41:33 by swijnber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	give_instructs(int *a, int *b, int print, ...)
{
	va_list	orders;
	char	*order;
	int		count;
	int		i;

	va_start(orders, print);
	count = va_arg(orders, int);
	i = 0;
	while (i++ < count)
	{
		order = va_arg(orders, char *);
		if (order[0] == 's')
			swap(a, b, print, order[1]);
		else if (order[0] == 'p')
			push(a, b, print, order[1]);
		else if (order[0] == 'r')
			rotate(a, b, print, order[1]);
		else if (order[0] == 'o')
			rrotate(a, b, print, order[1]);
	}
	va_end(orders);
	return (count);
}

int	algorithms_hq(int *a_, int argc)
{
	int			(*f)(int *, int, char);
	int			count[2];

	count[0] = brute_force(a_, argc);
	if (count[0] == -1)
		return ((int)ft_free((void *)a_, NULL) - 1);
	if (count[0] != INT_MAX)
		return ((int)ft_free((void *)a_, NULL) + count[0]);
	count[0] = algo_1(a_, argc, 'n');
	f = &algo_1;
	f(a_, argc, 'y');
	ft_printf("%i\n", count[0]);
	free(a_);
	return (count[0]);
}
