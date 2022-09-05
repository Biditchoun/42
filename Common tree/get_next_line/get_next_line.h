/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: swijnber <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/09 16:58:09 by swijnber          #+#    #+#             */
/*   Updated: 2022/09/05 06:50:23 by swijnber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <unistd.h>

typedef struct s_list
{
	char	*line;
	char	*rt;
}	t_two;

char	*get_next_line(int fd);
char	*ft_strndup(const char *s, int n);
char	*ft_strjoinfree(char *s1, char *s2, int sz);

#endif
