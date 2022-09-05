/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: swijnber <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/22 16:22:17 by swijnber          #+#    #+#             */
/*   Updated: 2022/09/05 05:31:25 by swijnber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <fcntl.h>
#include "get_next_line.h"
#include <stdio.h>
int	main()
{
	int	fd, fd2;
	int i;
	char *text;

	fd = open("text", O_RDONLY);
	fd2 = open("text2", O_RDONLY);
	i = -2;
	while (i)
	{
		text = get_next_line(fd);
		printf("Main: %s", text);
		if (!text)
			i = 0;
		free(text);
	}
	close(fd);
	close(fd2);
	return (0);
}
