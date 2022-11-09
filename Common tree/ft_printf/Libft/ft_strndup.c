/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strndup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: swijnber <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 12:09:22 by swijnber          #+#    #+#             */
/*   Updated: 2022/11/09 12:10:37 by swijnber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strndup(const char *s, int n)
{
	char	*c;
	int		l;

	if (!s)
		return (NULL);
	l = ft_min(ft_strlen(s) + 1, n);
	c = malloc(l * sizeof (const char));
	if (!c)
		return (NULL);
	ft_strlcpy(c, s, l);
	return (c);
}
