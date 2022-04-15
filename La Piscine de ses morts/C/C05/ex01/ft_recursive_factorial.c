/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_recursive_factorial.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: swijnber <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/21 21:30:17 by swijnber          #+#    #+#             */
/*   Updated: 2022/02/23 17:16:01 by swijnber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_recursive_factorial(int nb)
{
	if (nb < 0)
		return (0);
	if (nb > 1)
		nb = ft_recursive_factorial(nb - 1) * nb;
	else if (nb == 1 || nb == 0)
		return (1);
	return (nb);
}
