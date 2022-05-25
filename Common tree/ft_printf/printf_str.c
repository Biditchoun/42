/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_str.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: swijnber <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/24 18:53:02 by swijnber          #+#    #+#             */
/*   Updated: 2022/05/25 22:06:15 by swijnber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "libftprintf.h"

static void	filling(char *str, char c, int n)
{
	while (n > -1)
		str[n--] = c;
}

static char	*minus(char *s, char *rt, t_list flag_list, int len)
{
	ft_strlcpy(rt, s, len + 1);
	filling(&rt[len], ' ', flag_list.width - len);
	rt[flag_list.width + 1] = 0;
	return (rt);
}

char	*printf_str(t_list flag_list, char *arg)
{
	char	*rt;
	char	*s;
	int		len;

	s = ft_strdup(arg);
	if (!s)
		return (NULL);
	if (ft_strlen(s) > flag_list.pwidth)
		s[flag_list.pwidth] = 0;
	len = ft_strlen(s);
	if (!flag_list.width_ptr)
		flag_list.width = len;
	rt = malloc(sizeof (char) * (ft_max(flag_list.width, len) + 1));
	if (!rt)
		return (NULL);
	if (flag_list.minus)
		return (minus(s, rt, flag_listi, len));
	if (flag_list.zero)
		filling(rt, '0', flag_list.width - len);
	else
		filling(rt, ' ', flag_list.width - len);
	ft_strlcat(rt, s, len + 1);
	return (rt);
}
