/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcapitalize.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: swijnber <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/10 14:15:22 by swijnber          #+#    #+#             */
/*   Updated: 2022/02/10 14:41:35 by swijnber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strcapitalize(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] > 64 && str[i] < 91)
		{
			if (str[i - 1] > 47 && str[i - 1] < 58)
				str[i] = str[i] + 32;
			else if (str[i - 1] > 64 && str[i - 1] < 91)
				str[i] = str[i] + 32;
			else if (str[i - 1] > 96 && str[i - 1] < 123)
				str[i] = str[i] + 32;
		}
		if (str[i] > 96 && str[i] < 123)
		{
			if (str[i - 1] < 48 || (str[i - 1] > 57 && str[i - 1] < 65))
				str[i] = str[i] - 32;
			else if ((str[i - 1] > 90 && str[i - 1] < 97) || str[i - 1] > 122)
				str[i] = str[i] - 32;
		}
		i++;
	}
	return (str);
}
