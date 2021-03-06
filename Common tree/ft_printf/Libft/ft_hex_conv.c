/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hex_conv.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: swijnber <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/26 21:34:38 by swijnber          #+#    #+#             */
/*   Updated: 2022/05/29 08:27:48 by swijnber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_hex_conv(unsigned long long nb)
{
	unsigned long long	nbr;
	char				*rt;
	char				*base;
	int					i;

	if (!nb)
		return (ft_strdup("0"));
	i = 0;
	nbr = nb;
	while (nbr && i++ > -1)
		nbr /= 16;
	rt = malloc (sizeof (char) * (i + 1));
	if (!rt)
		return (NULL);
	base = "0123456789abcdef";
	rt[i] = 0;
	while (nb)
	{
		rt[--i] = base[nb % 16];
		nb /= 16;
	}
	return (rt);
}
