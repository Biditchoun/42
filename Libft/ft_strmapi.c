/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: swijnber <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/14 14:50:52 by swijnber          #+#    #+#             */
/*   Updated: 2022/04/15 10:57:15 by swijnber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char			*rt;
	unsigned int	i;

	if (!s)
		return (NULL);
	rt = ft_strdup(s);
	if (!rt)
		return (NULL);
	i = -1;
	if (f)
		while (rt[++i])
			rt[i] = f(i, rt[i]);
	return (rt);
}
