/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: swijnber <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/05 10:56:10 by swijnber          #+#    #+#             */
/*   Updated: 2022/02/05 12:12:27 by swijnber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <unistd.h>

void	ft_print_comb(void)
{
	write(1, "012, 013, 014, 015, 016, 017, 018, 019, 023, 024, 025, 026,", 59);
	write(1, " 027, 028, 029, 034, 035, 036, 037, 038, 039, 045, 046, 047", 59);
	write(1, ", 048, 049, 056, 057, 058, 059, 067, 068, 069, 078, 079, 08", 59);
	write(1, "9, 123, 124, 125, 126, 127, 128, 129, 134, 135, 136, 137, 1", 59);
	write(1, "38, 139, 145, 146, 147, 148, 149, 156, 157, 158, 159, 167, ", 59);
	write(1, "168, 169, 178, 179, 189, 234, 235, 236, 237, 238, 239, 245,", 59);
	write(1, " 246, 247, 248, 249, 256, 257, 258, 259, 267, 268, 269, 278", 59);
	write(1, ", 279, 289, 345, 346, 347, 348, 349, 356, 357, 358, 359, 36", 59);
	write(1, "7, 368, 369, 378, 379, 389, 456, 457, 458, 459, 467, 468, 4", 59);
	write(1, "69, 478, 479, 489, 567, 568, 569, 578, 579, 589, 678, 679, ", 59);
	write(1, "689, 789", 8);
}
