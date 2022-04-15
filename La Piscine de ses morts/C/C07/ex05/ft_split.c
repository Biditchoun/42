/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: swijnber <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/23 14:05:10 by swijnber          #+#    #+#             */
/*   Updated: 2022/02/24 21:49:25 by swijnber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
// PAS TERMINE
#include <stdlib.h>
/*
int	str_len(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

int	find(char *str, char *to_find, int i)
{
	int	j;
	int	k;

	while (str[i])
	{
		j = 0;
		k = i;
		while (str[k++] == to_find[j++])
			if (!to_find[j])
				return (i);
		i++;
	}
	return (0);
}

void	*strn_cat(char *dest, char *src, unsigned int nb, int b)
{
	unsigned int	i;
	unsigned int	j;

	i = 0;
	while (dest[i])
		i++;
	while (src[++j] && j < nb)
		dest[i++] = src[j];
	dest[i] = 0;
}

int	continuation(char **split, char *str, char *charset, int c)
{
	int	i;
	int	j;
	int	cu;
	int	m;

	i = 0;
	cu = c;
	while (c)
	{
		m = i;
		i = find(str, charset, i);
		if (i)
		{
			split[cu - c] = malloc(sizeof(char) * (str_len(charset) * 2 + i - m));
			split[cu - c][0] = 0;
			strn_cat(split[cu - c], charset, str_len(charset));
			if (i)
				strn_cat(split[cu - c], str); 
			writing(split[cu - c], str, m, i);
			writing(split[cu - c], charset, j, str_len(charset));
			split[cu - c--] = 0;
		}
	}
}

char	**ft_split(char *str, char *charset)
{
	char	**split
	int		i;
	int		c;
	int		b;

	if (!str || !charset)
		return (NULL);
	i = 0;
	c = 0;
	while (str[i])
	{
		i = find(str, charset, i);
		if (i || str_len(str) - i - str_len(charset))
			c++;
	}
	split = malloc(sizeof(char *) * (c + 1));
	split[c + 1][0] = 0;
	return (split);
}*/
