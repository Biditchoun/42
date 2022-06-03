/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utilities.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: swijnber <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/26 23:41:24 by swijnber          #+#    #+#             */
/*   Updated: 2022/06/03 18:05:59 by swijnber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	printfill(char *str, char c, int n)
{
	int	i;

	i = -1;
	while (++i < n)
		str[i] = c;
	if (n < 0)
		n = 0;
	str[i] = 0;
	return (n);
}

char	*printfree(char *s)
{
	free(s);
	return (NULL);
}
