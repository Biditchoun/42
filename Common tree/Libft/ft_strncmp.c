/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: swijnber <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/09 01:00:00 by swijnber          #+#    #+#             */
/*   Updated: 2022/05/06 14:39:02 by swijnber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	unsigned int	i;

	i = -1;
	while (s1 && s2 && ++i < n - 1)
		if (s1[i] != s2[i] /*|| !s1[i] || !s2[i]*/)
			break ;
	if (s1[i] != s2[i] && n)
		return ((unsigned char)s1[i] - (unsigned char)s2[i]);
	return (0);
}
