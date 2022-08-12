/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: swijnber <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/09 15:40:51 by swijnber          #+#    #+#             */
/*   Updated: 2022/08/09 17:12:19 by swijnber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

char	*ft_strjoinf(char const *s1, char const *s2, int sz)
{
	char	*rt;
	int		i;
	int		l;

	if (!s2)
		return (NULL);
	if (!s1)
		s1 = calloc(1, sizeof(char));
	if (!s1)
		return (NULL);
	l = ft_strlen(s1) + sz + 1;
	rt = malloc(l * sizeof (const char));
	if (!rt)
		return (NULL);
	l = -1;
	while (s1[++l])
		rt[l] = s1[l];
	i = 0;
	while (s2[i] && i < sz)
		rt[l++] = s2[i++];
	rt[l] = 0;
	free((void *)s1);
	if (sz == BUFFER_SIZE && s2[BUFFER_SIZE] != '\n')
		free((void *)s2);
	return (rt);
}

char	*ft_free(char *str)
{
	free((void *)str);
	return (NULL);
}
