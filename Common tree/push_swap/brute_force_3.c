/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithms_3.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: swijnber <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/10 05:35:56 by swijnber          #+#    #+#             */
/*   Updated: 2022/10/11 15:27:39 by swijnber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
/*static void	print_arr(int *arr)
{
	int i = 0;
	while (arr[i] != -1)
		ft_printf("%i ", arr[i++]);
	ft_printf("%i", arr[i]);
	ft_printf("push \n");
}*/
static int	fill_arr(int *arr, int n, int x, int y)
{
	int	i;

	arr[0] = n;
	i = 1;
	while (arr[i] != -1)
	{
		arr[i++] = x;
		if (arr[i] != -1)
			arr[i++] = y;
	}
	return (1);
}

int	push_validity_check(int *instructs, int p, int i)
{
	int	j;
	int	b;

	j = --i;
	b = p;
	while (b)
	{
		while (instructs[i] > 3)
			if (instructs[i--] == 4)
				b++;
		if (instructs[i] == 3 && b != 1)
		{
			if (!--b)
			{
				fill_arr(&instructs[i], 5, 1, 0);
				return (instructs_check(instructs));
			}
		}
		b--;
		i--;
	}
	//print_arr(instructs);
	fill_arr(&instructs[++i], 4, 0, 1);
	//print_arr(instructs);
	return (instructs_check(instructs));
}
