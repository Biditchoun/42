#include "push_swap.h"

void	walgo_1(t_stacks stacks, int argc)
{
	int	i;
	int	count;

	printstacks(stacks, argc);
	i = 1;
	while (stacks.a_[0] > 0)
	{
		count = 0;
		while (stacks.a_[0] != i)
			count += rotate(stacks, 'a');
		while (count--)
			ft_printf("ra\n");
		printstacks(stacks, argc);
		push(stacks, 'b');
		ft_printf("pb\n");
		printstacks(stacks, argc);
		i++;
	}
	count = 0;
	while (stacks.b_[0] > 0)
		count += push(stacks, 'a');
	while (count--)
		ft_printf("pa\n");
	printstacks(stacks, argc);
}

int	algo_1(t_stacks stacks, int argc)
{
	t_stacks	sbuf;
	int			i;
	int			count;

	sbuf = sbuf_init(stacks, argc);
	if (!sbuf.a || !sbuf.a_ || !sbuf.b || !sbuf.b_)
		return (-1);
	count = 0;
	i = 1;
	while (sbuf.a_[0] > 0)
	{
		while (sbuf.a_[0] != i)
			count += rotate(sbuf, 'a');
		count += push(sbuf, 'b');
		i++;
	}
	while (sbuf.b_[0] > 0)
		count += push(sbuf, 'a');
	freestacks(sbuf);
	return (count);
	}