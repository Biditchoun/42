/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_str.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: swijnber <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/24 18:53:02 by swijnber          #+#    #+#             */
/*   Updated: 2022/05/24 20:16:21 by swijnber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "libftprintf.h"

char	*printf_str(t_list flag_list, char *arg)
{
	if (ft_strlen(arg) > flag_list.pwidth)
		arg[flag_list.pwidth] = 0;

