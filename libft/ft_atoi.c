#include "libft.h"

int	ft_atoi(const char *str)
{
	size_t	i;
	int		res;
	int		sgn;

	sgn = 1;
	i = 0;
	res = 0;
	while ((str[i] == ' ') || ((str[i] > 8) && (str[i] < 14)))
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sgn = -1;
		i++;
	}
	while (ft_isdigit(str[i]))
	{
		res = res * 10 + str[i] - '0';
		i++;
	}
	return (res * sgn);
}
