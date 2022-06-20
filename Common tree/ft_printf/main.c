/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: swijnber <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/20 14:26:23 by swijnber          #+#    #+#             */
/*   Updated: 2022/06/20 15:45:54 by swijnber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#define PARAMS "%"
#include <stdio.h>
#include "ft_printf.h"
int main()
{
	int	a;
	int	b;
	printf("ft_printf :\n");
	a = ft_printf(PARAMS);
	printf("printf :\n");
	b = printf(PARAMS);
	printf("%i, %i\n", a, b);
}
