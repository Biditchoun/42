/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: swijnber <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/05 09:52:35 by swijnber          #+#    #+#             */
/*   Updated: 2022/11/09 10:58:22 by swijnber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
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

char	*ft_strjoinfree(char *s1, char *s2, int sz)
{
	char	*rt;
	int		i;
	int		j;

	if (!s2)
		return (NULL);
	if (!s1)
	{
		s1 = malloc(1);
		if (!s1)
			return (NULL);
		s1[0] = 0;
	}
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
