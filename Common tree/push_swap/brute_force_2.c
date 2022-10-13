/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithms_2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: swijnber <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/07 23:48:38 by swijnber          #+#    #+#             */
/*   Updated: 2022/10/11 15:27:23 by swijnber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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

static int	param_fill_arr(int *arr, int x, int y, int z)
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
	if (arr[1] == z)
	{
		if (z != 10)
			return (fill_arr(&arr[1], z + 1, 0, 1));
		if (arr[0] != 10)
			return (fill_arr(arr, arr[0] + 1, 0, 1));
		fill_arr(arr, 10, 10, 10);
		return (-1);
	}
	return (0);
}

static int	skcehc_tsrif(int *instructs, int i)
{
	if (instructs[i] == 0)
		return (param_fill_arr(&instructs[i], 0, 6, 20));
	else if (instructs[i] == 1)
		return (param_fill_arr(&instructs[i], 2, 10, 20));
	else if (instructs[i] == 2)
		return (param_fill_arr(&instructs[i], 1, 8, 20));
	else if (instructs[i] == 3)
		return (param_fill_arr(&instructs[i], 4, 20, 20));
	else if (instructs[i] == 4)
		return (param_fill_arr(&instructs[i], 3, 20, 20));
	else if (instructs[i] == 5)
		return (param_fill_arr(&instructs[i], 5, 6, 20));
	else if (instructs[i] == 6)
		return (param_fill_arr(&instructs[i], 0, 5, 20));
	else if (instructs[i] == 7)
		return (param_fill_arr(&instructs[i], 9, 10, 20));
	else if (instructs[i] == 8)
		return (param_fill_arr(&instructs[i], 2, 9, 1));
	else if (instructs[i] == 9)
		return (param_fill_arr(&instructs[i], 7, 8, 20));
	else if (instructs[i] == 10)
		return (param_fill_arr(&instructs[i], 1, 7, 8));
	return (0);
}

static int	first_checks(int *instructs, int i, int p)
{
	if (instructs[i] > 3 && p < 1)
		return (fill_arr(&instructs[i], 10, 10, 10) - 2);
	if (instructs[i] > 4 && p < 2)
		return (fill_arr(&instructs[i], 10, 10, 10) - 2);
	skcehc_tsrif(instructs, i);
	return (0);
}

int	instructs_check(int *instructs)
{
	int	i;
	int	p;
	int	rt;

	p = 0;
	i = -1;
	rt = 1;
	while (instructs[++i] != -1)
	{
		rt = first_checks(instructs, i, p);
		if (rt)
		{
			if (rt == 1)
				return (instructs_check(instructs));
			else
				return (1);
		}
		if (instructs[i] == 3)
			p++;
		else if (instructs[i] == 4)
			p--;
	}
	if (p)
		return (push_validity_check(instructs, p, i));
	return (0);
}
