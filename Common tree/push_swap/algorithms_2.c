/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithms_2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: swijnber <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/07 23:48:38 by swijnber          #+#    #+#             */
/*   Updated: 2022/10/08 02:49:04 by swijnber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
/*static void	print_arr(int *arr)
{
	int i = 0;
	while (arr[i] != -1)
		ft_printf("%i ", arr[i++]);
	ft_printf("fill \n");
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

/*static int	param_fill_arr(int *arr, int x, int y, int z)
{
	if (arr[1] == x && x != 10)
	{
		if (x != y - 1)
			return (fill_arr(&arr[1], x + 1, 0, 1));
		else
			arr[1]++;
	}
	if (arr[1] == y && y != 10)
	{
		if (y != z - 1)
			return (fill_arr(&arr[1], y + 1, 0, 1));
		else
			arr[1]++;
	}
	if (arr[1] == z && z != 10)
		return (fill_arr(&arr[1], z + 1, 0, 1));
	if (arr[0] != 10)
		return (fill_arr(arr, arr[0] + 1, 0, 1));
	fill_arr(arr, 10, 10, 10);
	return (-1);
}*/

int	instructs_check(int *instructs)
{
	int	i;
	int	p;
	int	rt;

	p = 0;
	i = -1;
	rt = 0;
	while (instructs[++i] != -1)
	{
		if (instructs[i] > 3 && p < 1)
			return (fill_arr(&instructs[i], 10, 10, 10));
		if (instructs[i] > 4 && p < 2)
			return (fill_arr(&instructs[i], 10, 10, 10));
		/*if (instructs[i] == 0)
			rt += param_fill_arr(&instructs[i], 0, 6, 20);
		else if (instructs[i] == 1)
			rt += param_fill_arr(&instructs[i], 2, 10, 20);
		else if (instructs[i] == 2)
			rt += param_fill_arr(&instructs[i], 1, 8, 20);
		else if (instructs[i] == 3)
			rt += param_fill_arr(&instructs[i], 4, 4, 20);
		else if (instructs[i] == 4)
			rt += param_fill_arr(&instructs[i], 3, 3, 20);
		else if (instructs[i] == 5)
			rt += param_fill_arr(&instructs[i], 5, 6, 20);
		else if (instructs[i] == 6)
			rt += param_fill_arr(&instructs[i], 0, 5, 20);
		else if (instructs[i] == 7)
			rt += param_fill_arr(&instructs[i], 9, 10, 20);
		else if (instructs[i] == 8)
			rt += param_fill_arr(&instructs[i], 2, 9, 10);
		else if (instructs[i] == 9)
			rt += param_fill_arr(&instructs[i], 7, 8, 20);
		else if (instructs[i] == 10)
			rt += param_fill_arr(&instructs[i], 1, 7, 8);
		if (rt)
		{
			if (rt == 1)
				return (0);
			else
				return (1);
		}*/
		(void)rt;
		if (instructs[i] == 3)
			p++;
		else if (instructs[i] == 4)
			p--;
	}
	return (0);
}
