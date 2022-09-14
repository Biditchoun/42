#include "libft.h"

void	*ft_free(void *s, void *rt)
{
	free(s);
	return (rt);
}