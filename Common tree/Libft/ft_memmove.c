/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: swijnber <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/07 02:41:20 by swijnber          #+#    #+#             */
/*   Updated: 2022/05/05 16:22:46 by swijnber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	size_t	i;

	i = -1;
	if (src < dest)
		while (n--)
			((char *)dest)[n] = ((char *)src)[n];
	else if (dest < src)
		while (++i < n)
			((char *)dest)[i] = ((char *)src)[i];
	return (dest);
}
