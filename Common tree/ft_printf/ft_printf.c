/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: swijnber <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/16 14:02:17 by swijnber          #+#    #+#             */
/*   Updated: 2022/05/16 18:09:35 by swijnber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libftprintf.h>

static f_list	pars_init()
{
	list	rt;

	rt{minus} = NULL;
	rt{zero} = NULL;
	rt{point} = NULL;
	rt{hash} = NULL;
	rt{space} = NULL;
	rt{plus} = NULL;
	return (rt);
}

static int	*parsing(const char *s, va_list args)
{
	char	*flags;
	char	type;
	int		i;
	int		parsrt[2];
	f_list	flag_list;

	flag_list = pars_init();
	flags = "0123456789-+# .";
	i = 0;
	while (ft_strchr(flags, s[i]))
		i++;
	type = s[i];

int	ft_printf(const char *s, ...)
{
	int		i;
	int		rt;
	int		parsrt[2];
	va_list	args;

	if (!s)
		return (0);
	va_start(args, s);
	rt = 0;
	i = 0;
	while (s[i])
	{
		if (s[i++] != '%')
			write(1, &s[i - 1], 1);
		else
		{
			parsrt = parsing(&s[i], args);
			i += parsrt[0];
			rt += parsrt[1];
		}
		rt++;
	}
	return (rt);
}
