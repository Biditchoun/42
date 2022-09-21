#include "push_swap.h"

static int	min_in_stack(int *a, int argc)
{
	int	i;
	int	j;
	int	content;

	i = -1;
	content = INT_MAX;
	while (++i < argc)
	{
		if (a[i] < content)
		{
			j = i;
			content = a[i];
		}
	}
	if (content == INT_MAX)
		return (INT_MAX);
	return (j);
}

int	*assign_sorting(int *a, int argc)
{
	int	*c;
	int	i;
	int	count;

	c = malloc(sizeof(int) * (argc + 1));
	if (!c)
		return (NULL);
	i = -1;
	while (++i < argc)
		if (a[i] == INT_MAX)
			c[i] = argc;
	count = 1;
	while (count - 1 < argc)
	{
		i = min_in_stack(a, argc);
		if (i == INT_MAX)
			break;
		c[i] = count++;
		a[i] = INT_MAX;
	}
	return (c);
}