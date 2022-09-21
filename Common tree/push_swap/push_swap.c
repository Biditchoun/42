#include "push_swap.h"

static int	error_rt(int argc, int *a, int *b)
{
	if (argc < 2)
		return (-1);
	write(2, "Error\n", 6);
	if (a)
		free(a);
	if (b)
		free (b);
	return (-1);
}

int	main(int argc, char **argv)
{
	int	*a;
	int	*b;
	int	*c;

	a = init_stack(argc, argv);
	if (!a)
		return (error_rt(argc, a, NULL));
	b = malloc(sizeof(int) * argc);
	if (!b)
		return (error_rt(argc, a, b));
	c = assign_sorting(a, argc - 1);
	if (!c)
		return (error_rt(argc, a, b));
	int i = 0;
	while (i < argc - 1)
		ft_printf("%i ", c[i++]);
	ft_printf("\n");
	return (0);
}