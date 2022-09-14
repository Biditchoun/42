#include "push_swap.h"

static int	error_rt(int argc)
{
	if (argc < 2)
		return (-1);
	write(1, "Error\n", 6);
	return (-1);
}

int	main(int argc, char **argv)
{
	int	*a;

	a = init_stack(argc, argv);
	if (!a)
		return (error_rt(argc));
	ft_printf("oui\n");
	return (0);
}