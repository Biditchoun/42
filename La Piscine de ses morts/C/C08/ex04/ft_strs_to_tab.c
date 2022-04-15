/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strs_to_tab.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: swijnber <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/24 14:25:41 by swijnber          #+#    #+#             */
/*   Updated: 2022/04/04 20:36:46 by swijnber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ft_stock_str.h"

int	str_len(char *str)
{
	int	i;

	i = 0;
	if (!str)
		return (0);
	while (str[i])
		i++;
	return (i);
}

char	*str_dump(char *src)
{
	int		i;
	char	*str;

	i = 0;
	if (!src)
		return (NULL);
	while (src[i])
		i++;
	str = malloc(sizeof(*src) * (i + 1));
	if (!str)
		return (NULL);
	i = -1;
	while (src[++i])
		str[i] = src[i];
	str[i] = 0;
	return (str);
}

struct s_stock_str	*ft_strs_to_tab(int ac, char **av)
{
	t_stock_str	*st;
	int			i;

	if (ac < 1 || !av)
		return (NULL);
	st = malloc(sizeof(t_stock_str) * (ac + 1));
	if (!st)
		return (NULL);
	i = -1;
	while (++i < ac)
	{
		st[i].size = str_len(av[i]);
		st[i].str = av[i];
		st[i].copy = str_dump(av[i]);
		if (!st[i].copy)
			return (NULL);
	}
	st[i].size = 0;
	st[i].str = 0;
	st[i].copy = 0;
	return (st);
}
