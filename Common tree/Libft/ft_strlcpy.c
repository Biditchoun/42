/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: swijnber <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/07 04:29:02 by swijnber          #+#    #+#             */
/*   Updated: 2022/04/15 10:58:31 by swijnber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t	i;

	if (!src || !dst || !size)
		return (ft_strlen(src));
	i = -1;
	while (++i < size && src[i])
		dst[i] = src[i];
	if (i == size)
		dst[i - 1] = 0;
	else
		dst[i] = 0;
	return (ft_strlen(src));
}
