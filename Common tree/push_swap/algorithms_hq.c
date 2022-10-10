/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithms_hq.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: swijnber <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/29 18:11:53 by swijnber          #+#    #+#             */
/*   Updated: 2022/10/10 01:29:25 by swijnber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	give_instructs(t_stacks stacks, char print, int orders_count, ...)
{
	va_list	orders;
	char	*order;
	int		i;

	va_start(orders, orders_count);
	i = 0;
	while (i++ < orders_count)
	{
		order = va_arg(orders, char *);
		if (order[0] == 's')
			swap(stacks, print, order[1]);
		else if (order[0] == 'p')
			push(stacks, print, order[1]);
		else if (order[0] == 'r')
			rotate(stacks, print, order[1]);
		else if (order[0] == 'o')
			rrotate(stacks, print, order[1]);
	}
	va_end(orders);
	return (orders_count);
}

t_stacks	sbuf_init(t_stacks stacks, int argc)
{
	t_stacks	sbuf;

	sbuf.a = ft_arrcp(stacks.a, argc - 1);
	sbuf.a_ = ft_arrcp(stacks.a_, argc);
	sbuf.b = ft_arrcp(stacks.b, argc - 1);
	sbuf.b_ = ft_arrcp(stacks.b_, argc);
	if (!sbuf.a || !sbuf.a_ || !sbuf.b || !sbuf.b_)
		freestacks(sbuf);
	return (sbuf);
}

void	algorithms_hq(t_stacks stacks, int argc)
{
	int	(*f)(t_stacks, int, char);
	int	count[2];

	count[0] = algo_1(stacks, argc);
	if (count[0] != INT_MAX)
		freestacks(stacks);
	if (count[0] != INT_MAX)
		return ;
	count[0] = algo_2(stacks, argc, 'n');
	f = &algo_2;
	f(stacks, argc, 'y');
	ft_printf("%i\n", count[0]);
	printstacks(stacks, argc);
	freestacks(stacks);
}
