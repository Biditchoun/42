#include "push_swap.h"

int	shift_down(int *a, int *a_)
{
	int	i;
	int	rt;

	i = 0;
	while (a_[i] > 0)
		i++;
	rt = i;
	while (i)
	{
		a[i] = a[i - 1];
		a_[i] = a_[i - 1];
		i--;
	}
	return (rt);
}

int	shift_up(int *a, int *a_)
{
	int	i;

	i = 0;
	while (a_[++i] > 0)
	{
		a[i - 1] = a[i];
		a_[i - 1] = a_[i];
	}
	a[--i] = INT_MAX;
	a_[i] = a_[i + 1];
	return (i);
}