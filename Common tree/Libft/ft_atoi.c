/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: swijnber <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/09 09:22:42 by swijnber          #+#    #+#             */
/*   Updated: 2022/05/05 16:56:16 by swijnber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	weird_shit(int m, unsigned long long nb, int p)
{
	long long	nba;

	if (!m && (nb > 9223372036854775807 || p > 18))
		return (-1);
	if (m && (nb > 9223372036854775807 || p > 18))
		return (0);
	nba = nb;
	if (m)
		nba = -nba;
	return (nba);
}

int	ft_atoi(const char *nptr)
{
	int					i;
	int					m;
	int					xp;
	unsigned long long	nb;

	i = 0;
	m = 0;
	nb = 0;
	while (nptr[i] == 32 || (nptr[i] > 8 && nptr[i] < 14))
		i++;
	if (nptr[i] == '+' || nptr[i] == '-')
		if (nptr[i++] == '-')
			m++;
	xp = i;
	while (nptr[i] >= '0' && nptr[i] <= '9')
		nb = nb * 10 + nptr[i++] - '0';
	return (weird_shit(m, nb, i - xp - 1));
}
