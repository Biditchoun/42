#include "push_swap.h"

static void	swapping (int *a, int *a_, int argc)
{
	int	buf;
	
	if ((a[0] == INT_MAX && a_[0] != argc) || (a[1] == INT_MAX && a_[1] != argc)
			|| (!a_[argc] && (a[0] == INT_MAX || a[1] == INT_MAX)))
			return ;
	buf = a[0];
	a[0] = a[1];
	a[1] = buf;
	buf = a_[0];
	a_[0] = a_[1];
	a_[1] = buf;
}

void	swap(t_stacks stacks, int argc, char which)
{
	argc--;
	if (which == 'a')
		swapping(stacks.a, stacks.a_, argc);
	else if (which == 'b')
		swapping(stacks.b, stacks.b_, argc);
}

static void	pushing(int *a, int *a_, int *b, int *b_)
{
	if (a_[0] < 1)
		return ;
	shift_down(b, b_);
	b[0] = a[0];
	b_[0] = a_[0];
	shift_up(a, a_);
}

void	push(t_stacks stacks, char which)
{
	if (which == 'a')
		pushing(stacks.a, stacks.a_, stacks.b, stacks.b_);
	else if (which == 'b')
		pushing(stacks.b, stacks.b_, stacks.a, stacks.a_);
}