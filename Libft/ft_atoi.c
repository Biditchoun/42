/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: swijnber <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/09 09:22:42 by swijnber          #+#    #+#             */
/*   Updated: 2022/04/09 09:42:51 by swijnber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *nptr)
{
	int	i;
	int	m;
	int	nb;

	i = 0;
	m = 0;
	nb = 0;
	if (!nptr)
		return (0);
	while (nptr[i] == 32 || (nptr[i] > 8 && nptr[i] < 14))
		i++;
	if (nptr[i] == '+' || nptr[i] == '-')
		if (nptr[i++] == '-')
			m++;
	while (nptr[i] >= '0' && nptr[i] <= '9')
		nb = nb * 10 + nptr[i++] - '0';
	if (m)
		nb = -nb;
	return (nb);
}
