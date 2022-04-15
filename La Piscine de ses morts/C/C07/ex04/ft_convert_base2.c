/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: swijnber <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/21 16:50:32 by swijnber          #+#    #+#             */
/*   Updated: 2022/02/21 20:08:01 by swijnber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	base_size(char *base)
{
	int	sz;
	int	i;

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
	return (sz);
}

int	number_size(char *str, char *base, int start)
{
	int	i;
	int	k;

	i = start;
	k = 0;
	while (str[i] && base[k])
	{
		if (str[i] == base[k++])
		{
			k = 0;
			i++;
		}
	}
	return (i);
}

int	exposant(int ex, int pui)
{
	int	n;

	if (pui < 0)
		return (0);
	if (!pui)
		return (1);
	n = ex;
	while (pui-- - 1)
		n *= ex;
	return (n);
}

int	decypher(char *str, char *base, int start)
{
	int	i;
	int	j;
	int	bs;
	int	nend;
	int	nb;

	i = start;
	j = 0;
	bs = base_size(base);
	if (bs < 2)
		return (0);
	nend = number_size(str, base, start) - 1;
	nb = 0;
	while (i >= start && base[j])
	{
		if (str[i] == base[j++])
		{
			nb = nb + exposant(bs, nend - i++) * (j - 1);
			j = 0;
		}
	}
	return (nb);
}

int	ft_atoi_base(char *str, char *base)
{
	int				i;
	int				m;
	unsigned int	n;
	int				nb;

	i = 0;
	m = 0;
	if (!str || !base)
		return (0);
	while (str[i] == 32 || (str[i] > 8 && str[i] < 14))
		i++;
	while (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			m++;
		i++;
	}
	n = decypher(str, base, i);
	if (m % 2 == 1)
		nb = -n;
	else
		nb = n;
	return (nb);
}
