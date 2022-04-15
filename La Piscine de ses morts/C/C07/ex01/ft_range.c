/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_range.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: swijnber <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/18 14:47:36 by swijnber          #+#    #+#             */
/*   Updated: 2022/02/21 15:10:52 by swijnber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	*ft_range(int min, int max)
{
	int	sz;
	int	*arr;
	int	i;

	if (min >= max)
		return (NULL);
	sz = max - min;
	arr = malloc(sizeof(int) * (sz + 1));
	if (!arr)
		return (NULL);
	i = 0;
	while (min < max)
		arr[i++] = min++;
	arr[i] = 0;
	return (arr);
}
