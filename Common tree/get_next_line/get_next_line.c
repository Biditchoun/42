/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: swijnber <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/08 14:49:14 by swijnber          #+#    #+#             */
/*   Updated: 2022/08/09 19:03:42 by swijnber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>
char	*get_next_line(int fd)
{
	char		*buff;
	static char	*line;
	char		*rt;
	int			i;

	i = BUFFER_SIZE;
	while (i == BUFFER_SIZE && !buff)
	{
		printf("oui");
		buff = malloc(BUFFER_SIZE + 1);
		if (!buff)
			return (NULL);
		read(fd, buff, BUFFER_SIZE);
		buff[BUFFER_SIZE] = 0;
		i = 0;
		while (i < BUFFER_SIZE && buff[i] && buff[i] != '\n')
			i++;
		if (buff[i] == '\n' && i < BUFFER_SIZE)
			i++;
		line = ft_strjoinf(line, buff, i);
		if (!line)
			return (ft_free(buff));
	}
	rt = line;
	line = buff;
	return (rt);
}
