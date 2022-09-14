/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: swijnber <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/09 07:42:51 by swijnber          #+#    #+#             */
/*   Updated: 2022/05/05 16:59:02 by swijnber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	unsigned int	i;
	int				l;

	if (!little[0])
		return ((char *)big);
	l = ft_strlen(little);
	i = -1;
	while (big[++i] && i + l <= len)
		if (!ft_strncmp(&big[i], little, l))
			return ((char *)&big[i]);
	return (NULL);
}
