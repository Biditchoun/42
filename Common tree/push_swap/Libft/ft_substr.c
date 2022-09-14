/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: swijnber <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/09 10:45:46 by swijnber          #+#    #+#             */
/*   Updated: 2022/04/20 15:59:19 by swijnber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*ft_strndup(char const *s, int size)
{
	char	*c;
	int		l;

	if (!s)
		return (NULL);
	l = ft_strlen(s) + 1;
	if (size < l)
		l = size + 1;
	c = malloc(l * sizeof (const char));
	if (!c)
		return (NULL);
	ft_strlcpy(c, s, l);
	return (c);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*c;

	if (!s)
		return (NULL);
	if (start > ft_strlen(s) - 1)
		return (ft_strdup(""));
	c = ft_strndup(&s[start], len);
	return (c);
}
