/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: swijnber <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/09 00:41:33 by swijnber          #+#    #+#             */
/*   Updated: 2022/04/20 18:00:32 by swijnber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int		i;

	i = ft_strlen(s);
	if (!c)
		return ((char *)&s[i]);
	while (--i > -1)
		if (s[i] == (unsigned char)c)
			return ((char *)&s[i]);
	return (NULL);
}
