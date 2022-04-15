/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: swijnber <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/15 16:37:15 by swijnber          #+#    #+#             */
/*   Updated: 2022/02/16 12:08:17 by swijnber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strstr(char *str, char *to_find)
{
	int	i;
	int	j;
	int	k;

	i = -1;
	if (!to_find[0])
		return (str);
	while (str[++i])
	{
		j = 0;
		k = i;
		while (str[k++] == to_find[j++])
			if (!to_find[j])
				return (&str[i]);
	}
	return (0);
}
