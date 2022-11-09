/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: swijnber <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/05 09:53:15 by swijnber          #+#    #+#             */
/*   Updated: 2022/09/07 12:05:36 by swijnber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 5
# endif

# include <stdlib.h>
# include <unistd.h>
# include <limits.h>

typedef struct s_list
{
	char	*line;
	char	*rt;
}	t_two;

char	*get_next_line(int fd);
char	*ft_strndup(const char *s, int n);
char	*ft_strjoinfree(char *s1, char *s2, int sz);

#endif
