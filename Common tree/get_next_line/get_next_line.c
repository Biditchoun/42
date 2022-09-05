/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: swijnber <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/08 14:49:14 by swijnber          #+#    #+#             */
/*   Updated: 2022/09/05 07:11:40 by swijnber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static t_two	freeing_things(t_two fctrt)
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

static t_two	read_next_line(int fd, char *line, char *buff)
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

static t_two	bsn_in_line(char *line, int i)
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
	static char	*line;
	int			i;
	char		*buff;
	t_two		fctrt;

	if (BUFFER_SIZE < 1 || read(fd, line, 0) < 0
		|| (!line && !read(fd, line, 1)))
		return (NULL);
	i = 0;
	while (line && line[i] && line[i] != '\n')
		i++;
	if (line && line[i] == '\n')
	{
		fctrt = bsn_in_line(line, i);
		line = fctrt.line;
		return (fctrt.rt);
	}
	buff = malloc(BUFFER_SIZE + 1);
	if (!buff)
		return (NULL);
	buff[BUFFER_SIZE - 1] = 0;
	fctrt = read_next_line(fd, line, buff);
	line = fctrt.line;
	return (fctrt.rt);
}
