/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_non_printable.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: swijnber <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/10 18:11:23 by swijnber          #+#    #+#             */
/*   Updated: 2022/02/24 18:57:00 by swijnber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
// ne passe pas la moulinette pour une raison qui m'echappe
void	hex_conv(long nb)
{
	char	*base;

	base = "0123456789abcdef";
	if (nb > 15)
		hex_conv(nb / 16);
	write (1, &base[nb % 16], 1);
}

void	ft_putstr_non_printable(char *str)
{
	int		i;

	if (!str)
		return ;
	i = -1;
	while (str[++i])
	{
		if (str[i] < 32 || str[i] == 127)
		{
			write (1, "\\", 1);
			if (str[i] < 16)
				write (1, "0", 1);
			hex_conv(str[i]);
		}
		else
			write(1, &str[i], 1);
	}
}
