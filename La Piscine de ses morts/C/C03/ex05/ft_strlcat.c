/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: swijnber <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/15 18:24:15 by swijnber          #+#    #+#             */
/*   Updated: 2022/02/15 20:31:22 by swijnber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

unsigned int	ft_strlcat(char *dest, char *src, unsigned int size)
{
	unsigned int	i;
	unsigned int	j;
	unsigned int	k;

	i = 0;
	j = 0;
	while (dest[i])
		i++;
	while (src[j])
		j++;
	if (i > size)
		return (j + size);
	j = -1;
	k = i;
	while (src[++j] && i + 1 < size)
		dest[i++] = src[j];
	dest[i] = 0;
	while (src[j])
		j++;
	return (k + j);
}
