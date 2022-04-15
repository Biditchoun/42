/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ultimate_range.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: swijnber <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/21 14:55:13 by swijnber          #+#    #+#             */
/*   Updated: 2022/02/24 19:13:13 by swijnber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_ultimate_range(int **range, int min, int max)
{
	int	i;
	int	*arr;
	int	m;

	if (max <= min)
	{
		range = NULL;
		return (0);
	}
	arr = malloc(sizeof(int) * (max - min));
	if (!arr)
		return (-1);
	i = 0;
	m = min;
	while (m < max)
		arr[i++] = m++;
	arr[i] = 0;
	*range = arr;
	return (max - min);
}
