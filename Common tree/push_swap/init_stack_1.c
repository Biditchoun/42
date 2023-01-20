/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_stack_1.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: swijnber <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/29 18:12:23 by swijnber          #+#    #+#             */
/*   Updated: 2023/01/17 17:31:31 by swijnber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	params_checking(int argc, char **argv, int bf)
{
	int	i;
	int	j;

	if (argc < 3)
		return (1);
	i = 0;
	while (argv[++i + bf])
	{
		j = 0;
		while (ft_isdigit(argv[i + bf][j]) || (!j && argv[i + bf][j] == '-'))
			j++;
		if (argv[i + bf][j])
			return (1);
	}
	return (0);
}

static int	*fill_stack(char **argv, int *a, int bf)
{
	int	i;
	int	j;

	i = 0;
	while (argv[++i + bf])
	{
		if (!argv[i + bf][0])
			return (ft_free((void *)a, NULL));
		a[i - 1] = ft_atoi(argv[i + bf]);
		if (!a[i - 1])
		{
			j = 0;
			while (argv[i + bf][j] == '0')
				j++;
			if (argv[i + bf][j])
				return (ft_free((void *)a, NULL));
		}
	}
	return (a);
}

static int	*check_duplicate(int argc, int *a)
{
	int	i;
	int	j;

	i = -1;
	while (++i < argc)
	{
		j = i;
		while (++j < argc)
			if (a[i] == a[j])
				return (ft_free((void *)a, NULL));
	}
	return (a);
}

int	*init_a(int argc, char **argv, int bf)
{
	int	*a;

	if (params_checking(argc, argv, bf))
		return (NULL);
	a = malloc(sizeof(int) * (argc - bf));
	if (!a)
		return (NULL);
	a = fill_stack(argv, a, bf);
	if (!a)
		return (NULL);
	a = check_duplicate(argc - 1 - bf, a);
	return (a);
}
