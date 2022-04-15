/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: swijnber <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/15 16:00:49 by swijnber          #+#    #+#             */
/*   Updated: 2022/02/15 16:09:14 by swijnber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strncat(char *dest, char *src, unsigned int nb)
{
	unsigned int	i;
	unsigned int	j;

	i = 0;
	j = -1;
	while (dest[i])
		i++;
	while (src[++j] && j < nb)
		dest[i++] = src[j];
	dest[i] = 0;
	return (dest);
}
