/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: swijnber <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/09 11:17:28 by swijnber          #+#    #+#             */
/*   Updated: 2022/04/15 09:47:23 by swijnber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*rt;
	int		l;

	if (!s1 || !s2)
		return (NULL);
	l = ft_strlen(s1) + ft_strlen(s2) + 1;
	rt = malloc(l * sizeof (const char));
	if (!rt)
		return (NULL);
	ft_strlcpy(rt, s1, l);
	ft_strlcat(rt, s2, l);
	return (rt);
}
