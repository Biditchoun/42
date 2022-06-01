/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_str.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: swijnber <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/24 18:53:02 by swijnber          #+#    #+#             */
/*   Updated: 2022/06/01 13:54:00 by swijnber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

static char	*minus(char *s, char *rt, t_f f_list, int len)
{
	ft_strlcpy(rt, s, len + 1);
	printfilling(&rt[len], ' ', f_list.width - len);
	rt[f_list.width] = 0;
	free(s);
	return (rt);
}

char	*printf_str(t_f f_list, char *arg)
{
	char	*rt;
	char	*s;
	int		len;

	s = ft_strdup(arg);
	if (!s)
		return (NULL);
	if (f_list.point && ft_strlen(s) > f_list.pwidth)
		s[f_list.pwidth] = 0;
	len = ft_strlen(s);
	if (!f_list.width_ptr)
		f_list.width = len;
	rt = malloc(sizeof (char) * (ft_max(f_list.width, len) + 1));
	if (!rt)
		return (printfree(s));
	if (f_list.minus)
		return (minus(s, rt, f_list, len));
	if (f_list.zero)
		printfilling(rt, '0', f_list.width - len);
	else
		printfilling(rt, ' ', f_list.width - len);
	ft_strlcpy(&rt[ft_max(f_list.width - len, 0)], s, len + 1);
	free(s);
	return (rt);
}
