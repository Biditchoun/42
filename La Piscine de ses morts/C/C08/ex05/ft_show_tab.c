/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_show_tab.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: swijnber <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/24 15:05:05 by swijnber          #+#    #+#             */
/*   Updated: 2022/02/24 15:39:23 by swijnber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "ft_stock_str.h"

void	putnbr(int nb)
{
	if (nb > 9)
		putnbr(nb / 10);
	nb = nb % 10 + '0';
	write (1, &nb, 1);
}

void	put_nbr(int nb)
{
	if (nb == -2147483648)
		write (1, "-2147483648", 11);
	else
	{
		if (nb < 0)
		{
			write(1, "-", 1);
			nb = -nb;
		}
		putnbr(nb);
	}
	write (1, "\n", 1);
}

void	put_str(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
		write (1, &str[i++], 1);
	write (1, "\n", 1);
}

void	ft_show_tab(struct s_stock_str *par)
{
	int	i;

	i = -1;
	while (par[++i].str)
	{
		put_str(par[i].str);
		put_nbr(par[i].size);
		put_str(par[i].copy);
	}
}
