/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: swijnber <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/16 16:30:47 by swijnber          #+#    #+#             */
/*   Updated: 2022/05/24 20:15:34 by swijnber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFTPRINTF_H
# define LIBFTPRINTF_H

# include <stdarg.h>

int		ft_printf(const char *s, ...);
int		printfing(const char *s, va_list args, t_list flag_list, char type);
char	*printf_char(t_list flag_list, char arg);
char	*printf_str(t_list flag_list, char *arg);

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
}t_list;

#endif
