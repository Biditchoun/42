/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: swijnber <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/09 10:45:46 by swijnber          #+#    #+#             */
/*   Updated: 2022/11/09 12:16:17 by swijnber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*c;

	if (!s)
		return (NULL);
	if (start > ft_strlen(s) - 1)
		return (ft_strdup(""));
	c = ft_strndup(&s[start], len);
	return (c);
}
