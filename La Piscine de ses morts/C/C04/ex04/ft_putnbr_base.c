/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: swijnber <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/16 12:14:27 by swijnber          #+#    #+#             */
/*   Updated: 2022/02/17 14:16:36 by swijnber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	put_nbr(unsigned int nbr, char *base, unsigned int sz)
{
	if (nbr > sz - 1)
		put_nbr(nbr / sz, base, sz);
	nbr = nbr % sz;
	write(1, &base[nbr], 1);
}

void	ft_putnbr_base(int nbr, char *base)
{
	unsigned int	sz;
	int				i;
	unsigned int	nb;

	sz = -1;
	while (base[++sz])
	{
		i = sz + 1;
		while (base[i])
			if (base[sz] == base[i++])
				return ;
		if (base[sz] == '+' || base[sz] == '-'
			|| base[sz] < 32 || base[sz] > 126)
			return ;
	}
	if (sz < 2 || !base)
		return ;
	if (nbr < 0)
	{
		write(1, "-", 1);
		nb = -nbr;
	}
	else
		nb = nbr;
	put_nbr(nb, base, sz);
}
