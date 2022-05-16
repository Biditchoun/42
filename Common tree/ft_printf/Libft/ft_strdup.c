/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: swijnber <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/09 10:29:43 by swijnber          #+#    #+#             */
/*   Updated: 2022/05/05 16:58:41 by swijnber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	char	*c;
	int		l;

	l = ft_strlen(s) + 1;
	c = malloc(l * sizeof (const char));
	if (!c)
		return (NULL);
	ft_strlcpy(c, s, l);
	return (c);
}
