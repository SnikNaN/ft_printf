#include "libft.h"

void	*ft_memchr(const void *b, int c, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n)
	{
		if (((unsigned char *)b)[i] == (unsigned char)c)
			return (&(((unsigned char *)b)[i]));
		i++;
	}
	return (NULL);
}
