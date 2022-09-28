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

static int	*fill_stack(char **argv, int *a)
{
	int	i;
	int	j;

	i = 0;
	while (argv[++i])
	{
		if (!argv[i][0])
			return (ft_free((void *)a, NULL));
		a[i - 1] = ft_atoi(argv[i]);
		if (!a[i - 1])
		{
			j = 0;
			while (argv[i][j] == '0')
				j++;
			if (argv[i][j])
				return (ft_free((void *)a, NULL));
		}
	}
	return (a);
}

static int	*check_duplicate(int argc, int *a)
{
	int	i;
	int	j;

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

int	*init_stack_a(int argc, char **argv)
{
	int	*a;

	if (params_checking(argc, argv))
		return (NULL);
	a = malloc(sizeof(int) * argc);
	if (!a)
		return (NULL);
	a = fill_stack(argv, a);
	if (!a)
		return (NULL);
	a = check_duplicate(argc - 1, a);
	return (a);
}