/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: swijnber <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/29 18:15:08 by swijnber          #+#    #+#             */
/*   Updated: 2022/10/10 05:38:47 by swijnber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "Libft/libft.h"

typedef struct s_tacks
{
	int	*a;
	int	*a_;
	int	*b;
	int	*b_;
}	t_stacks;

int			main(int argc, char **argv);
int			*init_stack_a(int argc, char **argv);
int			*init_stack_a_(int *a, int argc);
int			*init_stack_b(int argc);
int			*init_stack_b_(int *a_, int argc);

int			swap(t_stacks stacks, char print, char which);
int			push(t_stacks stacks, char print, char which);
int			rotate(t_stacks stacks, char print, char which);
int			rrotate(t_stacks stacks, char print, char which);
void		shift_down(int *a, int *a_, int i);
int			shift_up(int *a, int *a_);

void		algorithms_hq(t_stacks stacks, int argc);
t_stacks	sbuf_init(t_stacks stacks, int argc);
void		*freestacks(t_stacks stacks);
int			arrchr(int *a, int n);
int			give_instructs(t_stacks stacks, char print, int orders_count, ...);
int			algo_1(t_stacks stacks, int argc);
int			instructs_check(int *instructs);
int			push_validity_check(int *instructs, int p, int i);
int			algo_2(t_stacks stacks, int argc, char print);

void		printstacks(t_stacks stacks, int argc);

#endif
