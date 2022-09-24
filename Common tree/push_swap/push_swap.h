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

int		main(int argc, char **argv);
int		*init_stack_a(int argc, char **argv);
int		*init_stack_a_(int *a, int argc);
int		*init_stack_b(int argc);
int		*init_stack_b_(int *a_, int argc);

void	swap(t_stacks stacks, int argc, char which);
void	push(t_stacks stacks, char which);
void	shift_down(int *a, int *a_);
void	shift_up(int *a, int *a_);

#endif