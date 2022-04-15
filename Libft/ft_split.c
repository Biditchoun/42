/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: swijnber <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/12 09:37:23 by swijnber          #+#    #+#             */
/*   Updated: 2022/04/14 12:13:43 by swijnber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_slip(char **rt, int k, const char *s, int sz)
{
	rt[k] = malloc(sizeof (char) * (sz));
	if (!rt[k])
	{
		while (--k > -1)
			free(rt[k]);
		free(rt);
		return (1);
	}
	ft_strlcpy(rt[k], s, sz);
	return (0);
}

static char	**first_malloc(char **rt, const char *s, char c)
{
	int	i;
	int	sc;

	if (!s)
		return (NULL);
	sc = 1;
	i = -1;
	while (s[++i])
		if (s[i] == c)
			sc++;
	rt = malloc(sizeof (char *) * (sc + 1));
	if (!rt)
		return (NULL);
	return (rt);
}

char	**ft_split(const char *s, char c)
{
	int		i;
	int		j;
	int		k;
	char	**rt;

	rt = NULL;
	rt = first_malloc(rt, s, c);
	if (!rt)
		return (NULL);
	i = -1;
	j = 0;
	k = 0;
	while (s[++i])
	{
		if (s[i] == c)
		{
			if (ft_slip(rt, k++, &s[j], i - j + 1))
				return (NULL);
			j = i + 1;
		}
	}
	if (ft_slip(rt, k++, &s[j], i - j + 1))
		return (NULL);
	rt[k] = NULL;
	return (rt);
}
