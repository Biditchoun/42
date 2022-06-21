/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: swijnber <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/16 16:30:47 by swijnber          #+#    #+#             */
/*   Updated: 2022/06/21 19:49:25 by swijnber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include "Libft/libft.h"

typedef struct s_f
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
}	t_f;

int		ft_printf(const char *s, ...);
int		printfing(const char *s, va_list args, t_f lag, char type);
char	*printf_char(t_f lag, char arg);
char	*printf_str(t_f lag, char *arg);
char	*printf_void(t_f lag, void *arg);
char	*printf_int(t_f lag, int arg);
char	*printf_uint(t_f lag, unsigned int arg);
char	*printf_hex(t_f lag, unsigned int arg, char type);

int		printfill(char *str, char c, int n);
char	*printfree(char *s, char *rt);
int		printfreez(int *a, int rt);

#endif
