/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_combn.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: swijnber <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/06 16:24:57 by swijnber          #+#    #+#             */
/*   Updated: 2022/02/08 11:09:35 by swijnber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	put_char(char c)
{
	write (1, &c, 1);
}

void	affichage(int nb, int tab[])
{
	int	a;

	a = 0;
	while (a < nb)
	{
		put_char(tab[a] + '0');
		a++;
	}
	if (tab[0] != 10 - nb)
		write (1, ", ", 2);
}

void	boucle(int nb, int m, int tab[])
{
	while (tab[0] <= 10 - nb)
	{
		while (tab[nb - m] <= 10 - m)
		{
			affichage(nb, tab);
			tab[nb - m]++;
		}
		while (tab[nb - m] - 1 == 10 - m)
			m++;
		tab[nb - m]++;
		while (m != 1 && nb != 1)
		{
			tab[nb - m + 1] = tab[nb - m] + 1;
			m--;
		}
	}
}

void	ft_print_combn(int nb)
{
	int	tab[9];
	int	i;
	int	m;

	if (nb > 0 && nb < 10)
	{
		i = 0;
		m = 1;
		while (i < nb)
		{
			tab[i] = i;
			i++;
		}
		boucle(nb, m, tab);
	}
}
