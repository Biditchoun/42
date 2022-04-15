/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: swijnber <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/05 18:35:46 by swijnber          #+#    #+#             */
/*   Updated: 2022/02/06 14:48:13 by swijnber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write (1, &c, 1);
}

void	quatuor(int w, int x, int y, int z)
{
	ft_putchar(w);
	ft_putchar(x);
	ft_putchar(' ');
	ft_putchar(y);
	ft_putchar(z);
	if (w < '9' || x < '8')
	{
		ft_putchar(',');
		ft_putchar(' ');
	}
}

void	duo(int m, int n, int o, int p)
{
	while (o <= '9')
	{
		while (p <= '9')
		{
			quatuor(m, n, o, p);
			p++;
		}
		o++;
		p = '0';
	}
}

void	ft_print_comb2(void)
{
	int	a;
	int	b;
	int	c;
	int	d;

	a = '0';
	b = '0';
	c = '0';
	d = '1';
	while (a <= '9')
	{
		while (b <= '9')
		{
			duo(a, b, c, d);
			b++;
			c = a;
			d = b + 1;
		}
		a++;
		c = a;
		b = '0';
		d = '1';
	}
}
