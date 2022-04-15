/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fibonacci.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: swijnber <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/21 22:00:39 by swijnber          #+#    #+#             */
/*   Updated: 2022/02/21 23:24:16 by swijnber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_fibonacci(int index)
{
	if (index > 3)
		return (ft_fibonacci(index - 2) + ft_fibonacci(index - 1));
	if (index == 3)
		return (2);
	if (index == 2)
		return (1);
	if (index == 1)
		return (1);
	if (index == 0)
		return (0);
	return (-1);
}
