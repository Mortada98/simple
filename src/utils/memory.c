#include "cub3d.h"

void	ft_bzero(void *ptr, size_t size)
{
	size_t			i;
	unsigned char	*p;

	p = (unsigned char *)ptr;
	i = 0;
	while (i < size)
	{
		p[i] = 0;
		i++;
	}
}

void	*safe_malloc(size_t size)
{
	void	*ptr;

	ptr = malloc(size);
	if (!ptr)
	{
		write(2, "Error\nmalloc failed\n", 21);
		exit(EXIT_FAILURE);
	}
	return (ptr);
}
