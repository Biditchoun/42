/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: swijnber <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/07 02:41:20 by swijnber          #+#    #+#             */
/*   Updated: 2022/04/20 18:07:24 by swijnber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	size_t	i;
	char	*s;
	char	*d;

	if (!dest || !src)
		return (dest);
	i = -1;
	d = (char *)dest;
	s = (char *)src;
	if (s < d)
		while (n--)
			d[n] = s[n];
	else if (d < s)
		while (++i < n)
			d[i] = s[i];
	return (dest);
}
