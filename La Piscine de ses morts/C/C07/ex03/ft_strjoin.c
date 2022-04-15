/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: swijnber <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/21 15:37:03 by swijnber          #+#    #+#             */
/*   Updated: 2022/02/24 21:39:10 by swijnber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char	*writing(int size, char **strs, char *sep, char *str)
{
	int	i;
	int	j;
	int	k;

	j = -1;
	k = 0;
	while (++j < size && strs[j])
	{
		i = 0;
		while (strs[j][i])
			str[k++] = strs[j][i++];
		i = 0;
		while (sep[i] && j != size - 1 && strs[j + 1])
			str[k++] = sep[i++];
	}
	str[k] = 0;
	return (str);
}

char	*no_str(void)
{
	char	*str;

	str = malloc(sizeof(char));
	if (str)
		str[0] = 0;
	return (str);
}

char	*ft_strjoin(int size, char **strs, char *sep)
{
	int		i;
	int		j;
	int		sz;
	char	*str;

	if (!size)
		return (no_str());
	j = -1;
	sz = 0;
	while (++j < size)
	{
		i = 0;
		while (strs[j][i])
			i++;
		sz = sz + i - 1;
	}
	i = 0;
	while (sep[i])
		i++;
	str = malloc(sizeof(char) * (i * (j - 1) + sz));
	if (!str)
		return (NULL);
	str = writing(size, strs, sep, str);
	return (str);
}
