#include "libft.h"

char	*ft_strdup(const char *str)
{
	size_t	size;
	size_t	i;
	char	*res;

	size = ft_strlen(str);
	i = 0;
	res = (char *)malloc(sizeof(char) * (size + 1));
	if (res)
	{
		while (str[i])
		{
			res[i] = str[i];
			i++;
		}
		res[i] = '\0';
	}
	return (res);
}
