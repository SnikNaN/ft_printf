#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char			*res;
	unsigned int	i;

	if (!s)
		return (NULL);
	res = (char *)ft_calloc(ft_strlen(s) + 1, sizeof(char));
	if (res)
	{
		i = 0;
		while (s[i])
		{
			res[i] = (*f)(i, s[i]);
			i++;
		}
	}
	return (res);
}
