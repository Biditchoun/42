/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: swijnber <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/16 16:30:47 by swijnber          #+#    #+#             */
/*   Updated: 2022/05/16 18:09:32 by swijnber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFTPRINTF_H
# define LIBFTPRINTF_H

# include <stdarg.h>

ft_printf(const char *s, ...);

struct	f_list
{
	char	*minus;
	char	*zero;
	char	*point;
	char	*hash;
	char	*space;
	char	*plus;
}	
