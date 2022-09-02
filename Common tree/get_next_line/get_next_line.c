/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: swijnber <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/08 14:49:14 by swijnber          #+#    #+#             */
/*   Updated: 2022/09/02 04:57:12 by swijnber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static t_two	read_next_line(int fd, char *line, char *buff, int i)
{
	t_two	fctrt;

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
	if (!fctrt.line)
		free(fctrt.rt);
	if (fctrt.rt && !fctrt.rt[0])
	{
		if (fctrt.line)
			free((void *)fctrt.line);
		fctrt.rt = NULL;
	}
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
	char		*buff;
	int			i;
	t_two		fctrt;

	if (BUFFER_SIZE < 1 || fd < 0)
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
	i = BUFFER_SIZE;
	buff = ft_calloc(BUFFER_SIZE + 1, 1);
	if (!buff)
		return (NULL);
	fctrt = read_next_line(fd, line, buff, i);
	line = fctrt.line;
	return (fctrt.rt);
}
