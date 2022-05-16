/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: swijnber <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/12 10:50:22 by swijnber          #+#    #+#             */
/*   Updated: 2022/04/14 15:43:29 by swijnber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	power(int e, int p)
{
	int	n;

	if (p < 0)
		return (0);
	if (!p)
		return (1);
	n = e;
	while (p-- - 1)
		n *= e;
	return (n);
}

static int	n_size(int n)
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

char	*ft_itoa(int n)
{
	char	*rt;
	int		sz;
	int		i;
	int		p;

	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
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
		rt[i++] = (n / power(10, p)) % 10 + '0';
	rt[i] = 0;
	return (rt);
}
