/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: swijnber <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/09 16:58:09 by swijnber          #+#    #+#             */
/*   Updated: 2022/09/02 03:17:23 by swijnber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <unistd.h>
#include <stdio.h>
typedef struct s_list
{
	char	*line;
	char	*rt;
}	t_two;

size_t	ft_strlen(const char *s);
char	*ft_calloc(size_t nmemb, size_t size);
char	*ft_strndup(const char *s, int n);
char	*ft_strjoinfree(char const *s1, char const *s2, int sz);
char	*ft_free(char *str);

char	*get_next_line(int fd);

#endif
