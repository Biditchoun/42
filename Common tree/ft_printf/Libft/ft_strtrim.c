/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: swijnber <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/12 10:48:18 by swijnber          #+#    #+#             */
/*   Updated: 2022/04/20 16:01:16 by swijnber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	start(const char *s1, const char *set)
{
	int	s;
	int	i;

	s = -1;
	while (s1[++s])
	{
		i = -1;
		while (set[++i])
			if (s1[s] == set[i])
				break ;
		if (!set[i])
			break ;
	}
	return (s);
}

static int	end(const char *s1, const char *set)
{
	int	e;
	int	i;

	e = ft_strlen(s1);
	while (--e > -1)
	{
		i = -1;
		while (set[++i])
			if (s1[e] == set[i])
				break ;
		if (!set[i])
			break ;
	}
	return (e);
}

char	*ft_strtrim(const char *s1, const char *set)
{
	char	*rt;
	int		s;
	int		e;

	if (!s1 || !set)
		return (NULL);
	s = start(s1, set);
	e = end(s1, set);
	if (!s1[s])
		rt = ft_calloc(1, sizeof (char));
	else
		rt = ft_substr(s1, s, e - s + 1);
	return (rt);
}
