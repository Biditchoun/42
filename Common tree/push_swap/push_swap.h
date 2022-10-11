/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: swijnber <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/29 18:15:08 by swijnber          #+#    #+#             */
/*   Updated: 2022/10/11 08:15:48 by swijnber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "Libft/libft.h"

typedef struct s_tacks
{
	int		*a;
	int		*instructs;
	char	**base;
	int		argc;
}	t_brute;

int	main(int argc, char **argv);
int	*init_a(int argc, char **argv);
int	*init_a_(int *a, int argc);
int	*init_b_(int *a_, int argc);

int	give_instructs(int *a, int *b, int print, ...);
int	swap(int *a, int *b, char print, char which);
int	push(int *a, int *b, char print, char which);
int	rotate(int *a, int *b, char print, char which);
int	rrotate(int *a, int *b, char print, char which);
int	shift_up(int *a);

int	algorithms_hq(int *a_, int argc);
int	brute_force(int *a_, int argc);
int	instructs_check(int *instructs);
int	push_validity_check(int *instructs, int p, int i);
int	algo_1(int *a, int argc, char print);

#endif
