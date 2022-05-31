/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: swijnber <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/16 16:30:47 by swijnber          #+#    #+#             */
/*   Updated: 2022/05/31 11:02:04 by swijnber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFTPRINTF_H
# define LIBFTPRINTF_H

# include <stdarg.h>

int		ft_printf(const char *s, ...);
int		printfing(const char *s, va_list args, t_f f_list, char type);
char	*printf_char(t_f f_list, char arg);
char	*printf_str(t_f f_list, char *arg);
char	*printf_void(t_f f_list, void *arg);

int		printfilling(char *str, char c, int n);
char	*printfree(char *s);

typedef struct s_list
{
	char	*minus;
	char	*zero;
	char	*hash;
	char	*space;
	char	*plus;
	char	*point;
	char	*width_ptr;
	int		pwidth;
	int		width;
}t_f;

#endif
