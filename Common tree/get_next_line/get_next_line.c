/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: swijnber <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/08 14:49:14 by swijnber          #+#    #+#             */
/*   Updated: 2022/08/26 18:42:18 by swijnber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	char		*buff;
	static char	*line;
	char		*rt;
	int			i;

	if (BUFFER_SIZE < 1)
		return (NULL);
	i = 0;
	while (line && line[i] && line[i] != '\n')
		i++;
	if (line && line[i] == '\n')
	{
		rt = ft_strndup(line, ++i);
		if (!rt)
			return (NULL);
		buff = ft_strndup(&line[i], -1);
		if (!buff)
			return (ft_free(rt));
		free(line);
		line = buff;
		return (rt);
	}
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
		line = ft_strjoinfree(line, buff, i);
	}
	rt = line;
	line = ft_strndup(&buff[i], -1);
	free((void *)buff);
	if (!line)
		return (NULL);
	if (!rt[0])
		return (ft_free(line));
	return (rt);
}
