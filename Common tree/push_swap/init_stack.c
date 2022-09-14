#include "push_swap.h"

static int	params_checking(int argc, char **argv)
{
	int	i;
	int	j;

	if (argc < 3)
		return (1);
	i = 0;
	while (argv[++i])
	{
		j = 0;
		while (ft_isdigit(argv[i][j]) || (!j && argv[i][j] == '-'))
			j++;
		if (argv[i][j])
			return (1);
	}
	return (0);
}

int	*init_stack(int argc, char **argv)
{
	int	*a;
	int	i;
	int	j;

	if (params_checking(argc, argv))
		return (NULL);
	a = malloc(sizeof(int) * argc);
	if (!a)
		return (NULL);
	i = -1;
	while (argv[++i + 1])
		a[i] = ft_atoi(argv[i + 1]);
	i = -1;
	while (++i < argc)
	{
		j = i;
		while (++j < argc)
			if (a[i] == a[j])
				return (ft_free((void *)a, NULL));
	}
	return (a);
}