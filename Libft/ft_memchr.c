/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: swijnber <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/09 05:14:02 by swijnber          #+#    #+#             */
/*   Updated: 2022/04/09 06:38:40 by swijnber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*a;
	unsigned int	i;

	if (!s)
		return (NULL);
	a = (unsigned char *)s;
	i = -1;
	while (++i < n)
		if (a[i] == c)
			return (&a[i]);
	return (NULL);
}
