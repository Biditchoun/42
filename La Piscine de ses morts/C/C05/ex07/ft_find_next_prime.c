/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_find_next_prime.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: swijnber <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/21 23:01:49 by swijnber          #+#    #+#             */
/*   Updated: 2022/02/23 17:08:30 by swijnber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	prime(int nb, int i)
{
	if (nb % i && i < nb / i)
		return (prime(nb, i + 2));
	if (!(nb % i) && nb != i)
		return (0);
	return (1);
}

int	search(int nb, int i)
{
	if (!prime(nb, i))
		nb = search(nb + 2, i);
	return (nb);
}

int	ft_find_next_prime(int nb)
{
	if (nb < 3)
		return (2);
	if (!(nb % 2))
		nb += 1;
	return (search(nb, 3));
}
