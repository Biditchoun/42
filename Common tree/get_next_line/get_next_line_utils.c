/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: swijnber <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/09 15:40:51 by swijnber          #+#    #+#             */
/*   Updated: 2022/08/26 18:37:24 by swijnber         ###   ########.fr       */
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

char	*ft_calloc(size_t nmemb, size_t size)
{
	char			*rt;
	unsigned int	i;

	rt = malloc(nmemb * size);
	if (!rt)
		return (NULL);
	i = 0;
	while (i < nmemb * size)
		rt[i++] = 0;
	return (rt);
}

char	*ft_strndup(const char *s, int n)
{
	char	*rt;
	int		i;

	if (n < 0)
		n = ft_strlen(s);
	rt = malloc((n + 1) * sizeof (const char));
	if (!rt)
		return (NULL);
	i = -1;
	while (s[++i] && i < n)
		rt[i] = s[i];
	rt[i] = 0;
	return (rt);
}

char	*ft_strjoinfree(char const *s1, char const *s2, int sz)
{
	char	*rt;
	int		i;
	int		j;

	if (!s2)
		return (NULL);
	if (!s1)
		s1 = ft_calloc(1, sizeof(char));
	if (!s1)
		return (NULL);
	rt = malloc((ft_strlen(s1) + sz + 1) * sizeof (char));
	if (!rt)
		return (NULL);
	i = -1;
	while (s1[++i])
		rt[i] = s1[i];
	j = 0;
	while (s2[j] && j < sz)
		rt[i++] = s2[j++];
	rt[i] = 0;
	free((void *)s1);
	return (rt);
}

char	*ft_free(char *str)
{
	free((void *)str);
	return (NULL);
}
