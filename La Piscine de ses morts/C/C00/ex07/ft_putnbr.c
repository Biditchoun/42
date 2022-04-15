/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: swijnber <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/06 14:53:37 by swijnber          #+#    #+#             */
/*   Updated: 2022/02/12 17:17:04 by swijnber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	putchar(char c)
{
	write (1, &c, 1);
}

void	putnbr(int nb)
{
	if (nb > 9)
	{
		putnbr(nb / 10);
		nb = nb % 10;
	}
	putchar(nb + '0');
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
