/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: swijnber <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/29 18:14:45 by swijnber          #+#    #+#             */
/*   Updated: 2023/01/17 17:31:58 by swijnber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	error_rt(int *a, int argc)
{
	if (argc < 2)
		return (-1);
	write(2, "Error\n", 6);
	if (a)
		free(a);
	return (-1);
}

static int	check_order(int *a, int argc)
{
	int	i;

	i = -1;
	while (++i < argc - 1)
		if (a[i] != i + 1)
			return (0);
	return (1);
}

static int	bf_indicated(char **argv)
{
	int	bft;

	bft = 0;
	if (!ft_strncmp(argv[1], "Bruteforce=", 11)
		|| !ft_strncmp(argv[1], "bruteforce=", 11))
		bft++;
	return (bft);
}

static int	bf_tries(char **argv)
{
	int	bft;

	bft = 0;
	if (!ft_strncmp(argv[1], "Bruteforce=", 11)
		|| !ft_strncmp(argv[1], "bruteforce=", 11))
		bft = ft_atoi(&argv[1][11]);
	if (bft > 0)
		return (bft);
	return (12);
}

int	main(int argc, char **argv)
{
	int	*a;
	int	*a_;
	int	count;

	a = init_a(argc, argv, bf_indicated(argv));
	if (!a)
		return (error_rt(NULL, argc));
	a_ = init_a_(a, argc, bf_indicated(argv));
	if (!a_)
		return (error_rt(a, argc));
	free(a);
	if (check_order(a_, argc))
		return ((int)ft_free((void *)a_, NULL));
	count = algorithms_hq(a_, argc - bf_indicated(argv), bf_tries(argv));
	if (count < 0)
		return (error_rt(a_, argc));
	return (count);
}
