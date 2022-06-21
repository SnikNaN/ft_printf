#include "ft_printf.h"

int	ft_print_s(char *str, int flags[5])
{
	int	res;
	int	len;
	int	i;

	if (ft_strlen(str) > (size_t)flags[PRCSN] && flags[DOT])
		len = flags[PRCSN];
	else
		len = ft_strlen(str);
	if (len < flags[WIDTH])
		res = flags[WIDTH];
	else
		res = len;
	i = 0;
	if (!flags[ALIGN])
		ft_put_spaces(res - len, flags, 0);
	while (i < len)
	{
		ft_putchar_fd(str[i], 1);
		i++;
	}
	if (flags[ALIGN])
		ft_put_spaces(res - len, flags, 0);
	return (res);
}
