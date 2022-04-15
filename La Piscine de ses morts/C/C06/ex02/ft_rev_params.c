/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rev_params.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: swijnber <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/17 15:23:19 by swijnber          #+#    #+#             */
/*   Updated: 2022/02/17 16:16:02 by swijnber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	main(int argc, char **argv)
{
	int	i;
	int	j;

	if (argc < 2)
		return (0);
	i = argc;
	while (--i)
	{
		j = 0;
		while (argv[i][j])
			write (1, &argv[i][j++], 1);
		write (1, "\n", 1);
	}
}
