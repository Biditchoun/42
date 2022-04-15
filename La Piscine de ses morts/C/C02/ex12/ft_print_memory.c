/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_memory.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: swijnber <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/12 16:34:47 by swijnber          #+#    #+#             */
/*   Updated: 2022/02/15 15:57:05 by swijnber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	put_char(char c)
{
	write (1, &c, 1);
}

void	hex_conv(long nb)
{
	char	*base;

	base = "0123456789abcdef";
	if (nb > 15)
		hex_conv(nb / 16);
	put_char(base[nb % 16]);
}

int	addresse(long a, char *addr, int i)
{
	int	n;

	n = 0;
	if (a > 0)
		n = addresse(a / 16, addr, i);
	if (a != (long)addr + i)
		return (n + 1);
	while (16 - n != 0)
	{
		write (1, "0", 1);
		n++;
	}
	hex_conv(a);
	write (1, ": ", 2);
	return (0);
}

void	ecriture(int i, int j, unsigned char *tab)
{
	int	a;

	a = 0;
	while (i - j + a != 16)
	{
		write (1, "  ", 2);
		if (a % 2 == 0)
			write (1, " ", 1);
		a++;
	}
	while (i != j)
	{
		if (tab[j] > 31 && tab[j] < 127)
			put_char(tab[j]);
		else
			write (1, ".", 1);
		j++;
	}
	write (1, "\n", 1);
}

void	*ft_print_memory(void *addr, unsigned int size)
{
	long			a;
	unsigned int	i;
	unsigned int	j;
	unsigned char	*tab;

	i = 0;
	tab = addr;
	while (i < size)
	{
		a = (long)addr + i;
		addresse(a, addr, i);
		j = i;
		while (i < size && i - j < 16)
		{
			if (tab[i] < 16)
				write (1, "0", 1);
			hex_conv(tab[i]);
			if (i % 2 == 1)
				write (1, " ", 1);
			i++;
		}
		ecriture(i, j, tab);
	}
	return (addr);
}
