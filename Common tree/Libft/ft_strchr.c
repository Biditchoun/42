/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: swijnber <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/08 08:18:16 by swijnber          #+#    #+#             */
/*   Updated: 2022/04/19 16:13:26 by swijnber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	int		i;

	if (!c)
		return ((char *)&s[ft_strlen(s)]);
	i = -1;
	while (s[++i])
		if (s[i] == (unsigned char)c)
			return ((char *)&s[i]);
	return (NULL);
}
