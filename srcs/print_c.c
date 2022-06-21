#include "ft_printf.h"

int	ft_print_c(char c, int flags[5])
{
	int	res;

	res = 1;
	if (flags[WIDTH])
		res = flags[WIDTH];
	if (!flags[ALIGN])
		ft_put_spaces(flags[WIDTH] - 1, flags, 0);
	ft_putchar_fd(c, 1);
	if (flags[ALIGN])
		ft_put_spaces(flags[WIDTH] - 1, flags, 0);
	return (res);
}
