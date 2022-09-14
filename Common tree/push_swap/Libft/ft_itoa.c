/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: swijnber <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/12 10:50:22 by swijnber          #+#    #+#             */
/*   Updated: 2022/06/01 13:08:20 by swijnber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	n_size(long n)
{
	int	sz;

	sz = 1;
	while (n / 10)
	{
		sz++;
		n /= 10;
	}
	return (sz);
}

char	*ft_itoa(long n)
{
	char	*rt;
	int		sz;
	int		i;
	int		p;

	sz = n_size(n);
	p = sz;
	if (n < 0)
		sz++;
	rt = malloc(sizeof (char) * (sz + 1));
	if (!rt)
		return (NULL);
	i = 0;
	if (n < 0)
	{
		rt[i++] = '-';
		n = -n;
	}
	while (--p > -1)
		rt[i++] = (n / ft_power(10, p)) % 10 + '0';
	rt[i] = 0;
	return (rt);
}
