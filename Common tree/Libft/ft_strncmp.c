/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: swijnber <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/09 01:00:00 by swijnber          #+#    #+#             */
/*   Updated: 2022/05/05 17:50:43 by swijnber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	unsigned int	i;

	i = 0;
	if (!n)
		return (0);
	while (s1 && s2 && i < n - 1)
	{
		if (s1[i] == s2[i])
			i++;
		else
			break ;
	}
	if (s1[i] != s2[i])
	{
		if ((s1[i] == '\200' && !s2[i]) || (!s1[i] && s2[i] == '\200'))
			return (s2[i] - s1[i]);
		return (s1[i] - s2[i]);
	}
	return (0);
}
