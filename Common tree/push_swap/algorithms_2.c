#include "push_swap.h"

int	algo_3(t_stacks stacks, int argc)
{
	int 		count;
	int			rt;
	t_stacks	sbuf;

	sbuf = sbuf_init(stacks);
	if (!sbuf.a)
		return (NULL);
	argc--;
	rt = 0;
	count = 0;
	while (count < argc / 2)
	{
		if (sbuf.a_[0] < argc / 2 + 1)
			count += push(sbuf, 'b');
		else if (stacks.a_[1] < argc / 2)
			rt += rotate(sbuf, 'a');
		else
			rt += rrotate (sbuf, 'a');
	}
	if (sbuf.a_[0] > argc / 4 + 1)
	rt += count;
	while (stacks.b_[0] > 0)
		rt += push(sbuf, 'a');
	return (rt);
}