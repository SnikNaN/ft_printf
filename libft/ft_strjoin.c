#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*res;
	size_t	i;
	size_t	j;

	if (!s1 || !s2)
		return (NULL);
	res = (char *)ft_calloc(ft_strlen(s1) + ft_strlen(s2) + 1, sizeof(char));
	if (res)
	{
		i = 0;
		while (s1[i])
		{
			res[i] = s1[i];
			i++;
		}
		j = 0;
		while (s2[j])
		{
			res[i + j] = s2[j];
			j++;
		}
	}
	return (res);
}
