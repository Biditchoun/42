/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iterative_power.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: swijnber <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/21 21:45:20 by swijnber          #+#    #+#             */
/*   Updated: 2022/02/23 16:58:56 by swijnber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_iterative_power(int nb, int power)
{
	int	n;

	if (power < 0)
		return (0);
	if (power == 0)
		return (1);
	n = nb;
	while (power > 1)
	{
		n = n * nb;
		power--;
	}
	return (n);
}
