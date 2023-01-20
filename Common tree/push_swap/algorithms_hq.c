/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithms_hq.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: swijnber <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/29 18:11:53 by swijnber          #+#    #+#             */
/*   Updated: 2023/01/17 17:32:27 by swijnber         ###   ########.fr       */
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

/*static void	print_arr(int *arr)
{
	int i = 0;
	while (i < 10)
		ft_printf("%i ", arr[i++]);
	ft_printf("%i", arr[i]);
	ft_printf("\n");
}*/

int	algorithms_hq(int *a_, int argc, int bft)
{
	int	(*f)(int *, int, char);
	int	count;

	count = brute_force(a_, argc, bft);
	if (count == -1)
		return ((int)ft_free((void *)a_, NULL) - 1);
	if (count != INT_MAX)
		return ((int)ft_free((void *)a_, NULL) + count);
	count = algo_1(a_, argc, 'n');
	f = &algo_1;
	f(a_, argc, 'y');
	ft_printf("%i\n", count);
	free(a_);
	return (count);
}
