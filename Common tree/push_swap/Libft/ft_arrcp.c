#include "libft.h"

int	*ft_arrcp(int *arr, int n)
{
	int	*rt;
	int	i;

	if (!arr)
		return (NULL);
	rt = malloc(n * sizeof(int));
	if (!rt)
		return (NULL);
	i = -1;
	while (++i < n)
		rt[i] = arr[i];
	return (rt);
}