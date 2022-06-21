#include "libft.h"

int 	ft_chr_in_set(char c, char *set)
{
	while (*set)
	{
		if (c == *set)
			return (1);
		set++;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	start;
	size_t	len;

	if (!s1 || !set)
		return (NULL);
	start = 0;
	while (s1[start] && ft_chr_in_set(s1[start], (char *)set))
		start++;
	len = ft_strlen(s1);
	while (len > start && ft_chr_in_set(s1[len - 1], (char *)set))
		len--;
	return (ft_substr(s1, start, len - start));
}
