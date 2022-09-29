/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_arrcp.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: swijnber <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/29 18:16:02 by swijnber          #+#    #+#             */
/*   Updated: 2022/09/29 18:16:04 by swijnber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	*ft_arrcp(int *arr, int n)
{
	int	*rt;
	int	i;

	if (!arr)
		return (NULL);
	rt = malloc(n * sizeof(int));
	if (!rt)
		return (NULL);
	i = -1;
	while (++i < n)
		rt[i] = arr[i];
	return (rt);
}
