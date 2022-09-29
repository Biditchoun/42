/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithms_hq.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: swijnber <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/29 18:11:53 by swijnber          #+#    #+#             */
/*   Updated: 2022/09/29 18:59:42 by swijnber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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

static void	argc_four(t_stacks stacks, int argc)
{
	argc--;
	if (stacks.a_[0] == argc)
		rotate(stacks, 'a');
	else if (stacks.a_[1] == argc && argc == 3)
		rrotate(stacks, 'a');
	if (stacks.a_[0] != 1)
		swap(stacks, 'a');
}

void	algorithms_hq(t_stacks stacks, int argc)
{
	void	(*algo_ptr)(t_stacks, int);
	int		algo_count[2];
	//int		buf;

	if (argc < 5)
		argc_four(stacks, argc);
	else
	{algo_ptr = walgo_1;
	algo_count[1] = algo_1(stacks, argc);
	ft_printf("\nCount : %i\n\n", algo_count[1]);
	algo_ptr(stacks, argc);
	//buf = algo_2(stacks, argc);
	}
	printstacks(stacks, argc);
	freestacks(stacks);
}
