/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: swijnber <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/09 07:09:55 by swijnber          #+#    #+#             */
/*   Updated: 2022/05/05 16:33:25 by swijnber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned int	i;
	unsigned char	*a;
	unsigned char	*b;

	if (!n)
		return (0);
	i = 0;
	a = (unsigned char *)s1;
	b = (unsigned char *)s2;
	while (i < n - 1)
	{
		if (a[i] == b[i])
			i++;
		else
			break ;
	}
	if (a[i] != b[i])
		return (a[i] - b[i]);
	return (0);
}
