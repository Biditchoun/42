/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: swijnber <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/08 07:03:51 by swijnber          #+#    #+#             */
/*   Updated: 2022/04/12 17:12:42 by swijnber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *restrict dest, const void *restrict src, size_t n)
{
	unsigned int	i;
	char			*a;
	char			*b;

	if (!dest || !src)
		return (dest);
	i = -1;
	a = (char *)dest;
	b = (char *)src;
	while (++i < n)
		a[i] = b[i];
	return (dest);
}
