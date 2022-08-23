/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: swijnber <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/08 14:49:14 by swijnber          #+#    #+#             */
/*   Updated: 2022/08/23 17:51:23 by swijnber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	char		*buff;
	static char	*line;
	char		*rt;
	int			i;

	i = BUFFER_SIZE;
	buff = ft_calloc(BUFFER_SIZE + 1, 1);
	if (!buff)
		return (NULL);
	while (i == BUFFER_SIZE && buff[i - 1] != '\n')
	{
		read(fd, (void *)buff, BUFFER_SIZE);
		buff[BUFFER_SIZE] = 0;
		i = 0;
		while (i < BUFFER_SIZE && buff[i] && buff[i] != '\n')
			i++;
		if (buff[i] == '\n')
			i++;
		line = ft_strjoinf(line, buff, i);
	}
	rt = line;
	line = ft_strdup(&buff[i]);
	free((void *)buff);
	if (!line)
		return (NULL);
	if (!rt[0])
		return (ft_free(line));
	return (rt);
}
