/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_prime.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: swijnber <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/21 22:35:49 by swijnber          #+#    #+#             */
/*   Updated: 2022/02/23 19:46:43 by swijnber         ###   ########.fr       */
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

int	ft_is_prime(int nb)
{
	int	i;

	i = 3;
	if (nb == 2)
		return (1);
	if (nb < 2 || !(nb % 2))
		return (0);
	return (prime(nb, i));
}
