/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: swijnber <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/18 11:54:14 by swijnber          #+#    #+#             */
/*   Updated: 2022/02/24 19:08:36 by swijnber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char	*ft_strdup(char *src)
{
	int		i;
	char	*str;

	i = 0;
	while (src[i])
		i++;
	str = malloc(sizeof(*src) * i);
	if (!str)
		return (NULL);
	i = -1;
	while (src[++i])
		str[i] = src[i];
	str[i] = 0;
	return (str);
}
