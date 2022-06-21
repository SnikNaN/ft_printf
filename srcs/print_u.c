#include "ft_printf.h"

static int	ft_ulen(unsigned int num, int flags[5])
{
	int	i;

	if (num == 0 && flags[DOT] && !flags[PRCSN])
		return (0);
	if (num == 0)
		return (1);
	i = 0;
	while (num > 0)
	{
		num /= 10;
		i++;
	}
	return (i);
}

int	ft_print_u(unsigned int num, int flags[5])
{
	int	res;
	int	len;

	if (ft_ulen(num, flags) < flags[PRCSN])
		len = flags[PRCSN];
	else
		len = ft_ulen(num, flags);
	if (len < flags[WIDTH])
		res = flags[WIDTH];
	else
		res = len;
	if (!flags[ALIGN])
		ft_put_spaces(res - len, flags, 1);
	ft_put_zeros(len - ft_ulen(num, flags));
	if (!(flags[DOT] && !flags[PRCSN] && !num))
		ft_putnbr_unsigned(num);
	if (flags[ALIGN])
		ft_put_spaces(res - len, flags, 1);
	return (res);
}
