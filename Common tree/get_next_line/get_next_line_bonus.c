/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: swijnber <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/05 09:51:44 by swijnber          #+#    #+#             */
/*   Updated: 2022/11/09 10:57:48 by swijnber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

t_two	freeing_things(t_two fctrt)
{
	if (!fctrt.line)
		free(fctrt.rt);
	if (fctrt.rt && !fctrt.rt[0])
	{
		if (fctrt.line)
			free((void *)fctrt.line);
		free(fctrt.rt);
		fctrt.rt = NULL;
	}
	return (fctrt);
}

t_two	read_next_line(int fd, char *line, char *buff)
{
	int		i;
	t_two	fctrt;

	i = BUFFER_SIZE;
	while (i == BUFFER_SIZE && buff[i - 1] != '\n')
	{
		i = read(fd, (void *)buff, BUFFER_SIZE);
		buff[i] = 0;
		i = 0;
		while (i < BUFFER_SIZE && buff[i] && buff[i] != '\n')
			i++;
		if (buff[i] == '\n')
			i++;
		line = ft_strjoinfree(line, buff, i);
	}
	fctrt.rt = line;
	fctrt.line = ft_strndup(&buff[i], -1);
	free((void *)buff);
	fctrt = freeing_things(fctrt);
	return (fctrt);
}

t_two	bsn_in_line(char *line, int i)
{
	char	*buff;
	t_two	fctrt;

	fctrt.rt = ft_strndup(line, ++i);
	buff = ft_strndup(&line[i], -1);
	if (!buff)
		if (fctrt.rt)
			free(fctrt.rt);
	free(line);
	fctrt.line = buff;
	return (fctrt);
}

char	*get_next_line(int fd)
{
	static char	*line[OPEN_MAX];
	int			i;
	char		*buff;
	t_two		fctrt;

	if (BUFFER_SIZE < 1 || read(fd, line[fd], 0) < 0)
		return (NULL);
	i = 0;
	while (line[fd] && line[fd][i] && line[fd][i] != '\n')
		i++;
	if (line[fd] && line[fd][i] == '\n')
	{
		fctrt = bsn_in_line(line[fd], i);
		line[fd] = fctrt.line;
		return (fctrt.rt);
	}
	buff = malloc(BUFFER_SIZE + 1);
	if (!buff)
		return (NULL);
	buff[BUFFER_SIZE - 1] = 0;
	fctrt = read_next_line(fd, line[fd], buff);
	line[fd] = fctrt.line;
	return (fctrt.rt);
}
