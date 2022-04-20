/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: swijnber <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/12 09:37:23 by swijnber          #+#    #+#             */
/*   Updated: 2022/04/20 17:19:52 by swijnber         ###   ########.fr       */
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
		return (0);
	}
	ft_strlcpy(rt[k], s, sz);
	return (1);
}

static char	**first_malloc(const char *s, char c)
{
	int		i;
	int		sc;
	char	**rt;

	sc = 0;
	i = 0;
	while (s[i])
	{
		while (s[i] == c && s[i])
			i++;
		if (s[i] != c && s[i])
			sc++;
		while (s[i] != c && s[i])
			i++;
	}
	rt = malloc(sizeof (char *) * (sc + 1));
	if (!rt)
		return (NULL);
	return (rt);
}

static int	banana_split(const char *s, char c, char **rt)
{
	int	i;
	int	j;
	int	k;

	i = 0;
	j = 0;
	k = 0;
	while (s[i])
	{
		while (s[i] == c && s[i])
			j = ++i;
		if (s[i] != c && s[i])
			while (s[i] != c && s[i])
				i++;
		if (s[i] && !ft_slip(rt, k++, &s[j], i - j + 1))
			return (0);
	}
	if (s[0] && s[i - 1] != c && !ft_slip(rt, k++, &s[j], i - j + 1))
		return (0);
	rt[k] = NULL;
	return (1);
}

char	**ft_split(const char *s, char c)
{
	char	**rt;

	if (!s)
		return (NULL);
	rt = first_malloc(s, c);
	if (!rt)
		return (NULL);
	if (!banana_split(s, c, rt))
		return (NULL);
	return (rt);
}
