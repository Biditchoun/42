/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: swijnber <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/07 09:38:09 by swijnber          #+#    #+#             */
/*   Updated: 2022/05/05 16:48:36 by swijnber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	unsigned int	i;
	unsigned int	j;
	unsigned int	ds;

	ds = ft_strlen(dst);
	if (ds > size)
		return (ft_strlen(src) + size);
	j = 0;
	i = ds;
	while (src[j] && i + 1 < size)
		dst[i++] = src[j++];
	dst[i] = 0;
	return (ds + ft_strlen(src));
}
