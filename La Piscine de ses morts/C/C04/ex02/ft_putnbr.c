/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: swijnber <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/16 11:16:51 by swijnber          #+#    #+#             */
/*   Updated: 2022/02/24 15:22:32 by swijnber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	putnbr(int nb)
{
	if (nb > 9)
		putnbr(nb / 10);
	nb = nb % 10 + '0';
	write (1, &nb, 1);
}

void	ft_putnbr(int nb)
{
	if (nb == -2147483648)
		write (1, "-2147483648", 11);
	else
	{
		if (nb < 0)
		{
			putchar('-');
			nb = -nb;
		}
		putnbr(nb);
	}
}
