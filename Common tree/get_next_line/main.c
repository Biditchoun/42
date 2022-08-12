/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: swijnber <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/08 14:26:22 by swijnber          #+#    #+#             */
/*   Updated: 2022/08/09 19:03:26 by swijnber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <fcntl.h>
#include "get_next_line.h"

int	main()
{
	int	fd;
	int i;
	char *line;

	fd = open("text", O_RDONLY);
	i = 1;
	while (i)
	{
		line = get_next_line(1);
		printf("%s", line);
		if (!line)
			i = 0;
	}
	return (0);
}
