#include "push_swap.h"

static void	rotating(int *a, int *a_)
{
	int	i;
	int	buf;
	int	buf_;

	if (a_[0] < 1 || a_[1] < 1)
		return ;
	buf = a[0];
	buf_ = a_[0];
	i = shift_up(a, a_);
	a[i] = buf;
	a_[i] = buf_;
}

int	rotate(t_stacks stacks, char which)
{
	if (which == 'a')
		rotating(stacks.a, stacks.a_);
	else if (which == 'b')
		rotating(stacks.b, stacks.b_);
	return (1);
}

static void	rrotating(int *a, int *a_)
{
	int i;
	int buf;

	if (a_[0] < 1 || a_[1] < 1)
		return ;
	i = 0;
	while (a_[i] > 0)
		i++;
	buf = a_[i];
	i = shift_down(a, a_);
	a[0] = a[i];
	a_[0] = a_[i];
	a[i] = INT_MAX;
	a_[i] = buf;
}

int	rrotate(t_stacks stacks, char which)
{
	if (which == 'a')
		rrotating(stacks.a, stacks.a_);
	else if (which == 'b')
		rrotating(stacks.b, stacks.b_);
	return (1);
}