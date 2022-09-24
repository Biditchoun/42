#include "push_swap.h"

static int	error_rt(t_stacks stacks, int argc)
{
	if (argc < 2)
		return (-1);
	write(2, "Error\n", 6);
	if (stacks.a)
		free(stacks.a);
	if (stacks.b)
		free(stacks.b);
	if (stacks.a_)
		free(stacks.a_);
	if (stacks.b_)
		free(stacks.b_);
	return (-1);
}

int	main(int argc, char **argv)
{
	t_stacks	stacks;

	stacks.a = init_stack_a(argc, argv);
	if (!stacks.a)
		return (error_rt(stacks, argc));
	stacks.b = init_stack_b(argc);
	if (!stacks.b)
		return (error_rt(stacks, argc));
	stacks.a_ = init_stack_a_(stacks.a, argc - 1);
	if (!stacks.a_)
		return (error_rt(stacks, argc));
	stacks.b_ = init_stack_b_(stacks.a_, argc);
	if (!stacks.b_)
		return (error_rt(stacks, argc));

	push(stacks, 'b');
	push(stacks, 'a');
	push(stacks, 'a');
	swap(stacks, argc, 'b');
	push(stacks, 'b');
	int i = 0;
	ft_printf("Stack a:\n");
	while (i < argc)
		ft_printf("%i ", stacks.a[i++]);
	ft_printf("\n");
	i = 0;
	while (i < argc)
		ft_printf("%i ", stacks.a_[i++]);
	ft_printf("\nStack b:\n");
	i = 0;
	while (i < argc)
		ft_printf("%i ", stacks.b[i++]);
	ft_printf("\n");
	i = 0;
	while (i < argc)
		ft_printf("%i ", stacks.b_[i++]);
	ft_printf("\n");
	return (0);
}