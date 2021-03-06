/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: swijnber <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/08 07:03:51 by swijnber          #+#    #+#             */
/*   Updated: 2022/05/05 17:31:35 by swijnber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	unsigned int	i;
	char			*a;
	char			*b;

	if ((!dest && !src) || !n)
		return (dest);
	i = -1;
	a = (char *)dest;
	b = (char *)src;
	while (++i < n)
		a[i] = b[i];
	return (dest);
}
