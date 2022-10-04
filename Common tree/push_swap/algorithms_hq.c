/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithms_hq.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: swijnber <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/29 18:11:53 by swijnber          #+#    #+#             */
/*   Updated: 2022/09/30 16:13:32 by swijnber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	give_instructions(t_stacks stacks, int orders_count, ...)
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
			swap(stacks, order[1]);
		else if (order[0] == 'p')
			push(stacks, order[1]);
		else if (order[0] == 'r')
			rotate(stacks, order[1]);
		else if (order[0] == 'o')
			rrotate(stacks, order[1]);
	}
	va_end(orders);
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
	if (argc < 5)
		algo_1(stacks, argc);
	else if (argc == 5)
		algo_2(stacks, argc);
	else
		algo_3(stacks, argc);
	printstacks(stacks, argc);
	freestacks(stacks);
}
