/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: swijnber <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/20 14:26:23 by swijnber          #+#    #+#             */
/*   Updated: 2022/11/09 19:04:25 by swijnber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#define PARAMS "%#.x, %#.x, %#.x, %#.x, %#.x, %#.x, %#.x, %#.x, %#.x, %#.x\n", 0, 5, -1, -10, 0x1234, -1862, 0xABCDE, INT_MIN, INT_MAX, UINT_MAX 
#include <stdio.h>
#include "ft_printf.h"
#include <fcntl.h>
#include <limits.h>

int main()
{
	int	a;
	int	b;
	printf("ft_printf :\n");
	a = ft_printf(PARAMS);
	printf("printf :\n");
	b = printf(PARAMS);
	printf("%i, %i\n", a, b);
	/*int fd1 = open("oui.a", O_RDONLY);
	int fd2 = open("oui.b", O_RDONLY);
	char oui[10000];
	read(fd1, oui, 10000);
	char non[10000];
	read(fd2, non, 10000);
	int i = 0;
	while (oui[i] && non[i])
	{
		if (oui[i] == non[i])
			printf("%c", oui[i]);
		else
			printf("\n\n!!! %c %c", oui[i], non[i]);
		i++;
	}*/
}
