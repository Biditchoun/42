/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnrchr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: swijnber <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/18 14:54:44 by swijnber          #+#    #+#             */
/*   Updated: 2022/05/19 19:46:46 by swijnber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnrchr(const char *s, int c, int n)
{
	int		i;

	if (!c)
		return ((char *)&s[ft_strlen(s)]);
	i = ft_min(ft_strlen(s), n);
	while (--i > -1)
		if (s[i] == (unsigned char)c)
			return ((char *)&s[i]);
	return (NULL);
}
