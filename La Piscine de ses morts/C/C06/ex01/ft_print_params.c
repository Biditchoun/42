/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_params.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: swijnber <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/17 14:57:24 by swijnber          #+#    #+#             */
/*   Updated: 2022/02/17 15:22:44 by swijnber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	main(int argc, char **argv)
{
	int	i;
	int	j;

	if (argc < 2)
		return (0);
	i = 0;
	while (argv[++i])
	{
		j = 0;
		while (argv[i][j])
			write (1, &argv[i][j++], 1);
		write (1, "\n", 1);
	}
}
