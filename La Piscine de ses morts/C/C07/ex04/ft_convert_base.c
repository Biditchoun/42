/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: swijnber <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/21 16:46:34 by swijnber          #+#    #+#             */
/*   Updated: 2022/02/24 21:38:03 by swijnber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_atoi_base(char *str, char *base);

int	ex_count(unsigned int nb, int nb2)
{
	unsigned int	n;
	int				c;
	int				ex;

	c = 0;
	if (nb2 < 0)
		n = -nb2;
	else
		n = nb2;
	ex = nb;
	while (nb <= n)
	{
		nb = nb * ex;
		c++;
	}
	return (c);
}

void	put_nbr(int nb, char *base, unsigned int sz, char *str)
{
	unsigned int	n;
	int				i;

	if (nb < 0)
	{
		n = -nb;
		str[0] = '-';
		str[1] = 0;
	}
	else
		n = nb;
	if (n > sz - 1)
		put_nbr(n / sz, base, sz, str);
	n = n % sz;
	i = 0;
	while (str[i])
		i++;
	str[i] = base[n];
	str[i + 1] = 0;
}

int	check_based_number(char *str, char *base)
{
	int	i;
	int	j;

	i = 0;
	while (str[i] == 32 || (str[i] > 8 && str[i] < 14))
		i++;
	while (str[i] == '+' || str[i] == '-')
		i++;
	j = 0;
	while (base[j])
	{
		if (str[i] == base[j++])
		{
			i++;
			j = 0;
		}
	}
	if (str[i] >= '0' && str[i] <= '9')
		return (0);
	return (1);
}

int	check_base(char *base)
{
	int	i;
	int	sz;

	sz = -1;
	while (base[++sz])
	{
		i = sz + 1;
		while (base[i])
			if (base[sz] == base[i++])
				return (0);
		if (base[sz] == '+' || base[sz] == '-'
			|| base[sz] < 32 || base[sz] > 126)
			return (0);
	}
	if (sz < 2 || !base)
		return (0);
	return (sz);
}

char	*ft_convert_base(char *nbr, char *base_from, char *base_to)
{
	int				nb_;
	char			*str;
	unsigned int	bs_sz;
	int				mal_sz;

	if (!check_base(base_from) || !check_base(base_to) || !nbr)
		return (NULL);
	nb_ = ft_atoi_base(nbr, base_from);
	bs_sz = check_base(base_to);
	mal_sz = ex_count(bs_sz, nb_);
	if (nb_ < 0)
		mal_sz++;
	str = malloc(sizeof(char) * mal_sz + 1);
	if (!str)
		return (NULL);
	str[0] = 0;
	put_nbr(nb_, base_to, bs_sz, str);
	return (str);
}
