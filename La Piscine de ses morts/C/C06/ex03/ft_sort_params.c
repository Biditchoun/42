/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_params.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: swijnber <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/17 16:18:46 by swijnber          #+#    #+#             */
/*   Updated: 2022/02/18 14:31:54 by swijnber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	put_str(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		write (1, &str[i++], 1);
	write (1, "\n", 1);
}

int	str_cmp(char *str, char *str2)
{
	int	i;

	i = -1;
	while (str[++i] || str2[i])
		if (str[i] != str2[i])
			return (str[i] - str2[i]);
	return (0);
}

void	str_swap(char **str, int i, int j)
{
	char	*a;

	a = str[i];
	str[i] = str[j];
	str[j] = a;
}

int	main(int argc, char **argv)
{
	int		i;
	int		j;

	if (argc < 2)
		return (0);
	if (argc == 2)
		put_str(argv[1]);
	else
	{
		i = 0;
		while (argv[++i])
		{
			j = i;
			while (argv[++j])
				if (str_cmp(argv[i], argv[j]) > 0)
					str_swap(argv, i, j);
		}
		i = 1;
		while (argv[i])
			put_str(argv[i++]);
	}
	return (0);
}
