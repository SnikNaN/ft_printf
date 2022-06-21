#include "ft_printf.h"

static void	ft_put_pointer(unsigned long long num)
{
	if (num < 16)
	{
		if (num < 10)
			ft_putchar_fd('0' + num, 1);
		else
			ft_putchar_fd('a' + num - 10, 1);
	}
	else
	{
		ft_put_pointer(num / 16);
		ft_put_pointer(num % 16);
	}
}

static int	ft_plen(unsigned long long num, int flags[5])
{
	int	i;

	if (num == 0 && flags[DOT] && !flags[PRCSN])
		return (0);
	if (num == 0)
		return (1);
	i = 0;
	while (num > 0)
	{
		num /= 16;
		i++;
	}
	return (i);
}

int	ft_print_p(unsigned long long pointer, int flags[5])
{
	int	res;
	int	len;

	if (ft_plen(pointer, flags) < flags[PRCSN])
		len = flags[PRCSN];
	else
		len = ft_plen(pointer, flags);
	if (len + 2 < flags[WIDTH])
		res = flags[WIDTH];
	else
		res = len + 2;
	if (flags[ZERO])
		ft_putstr_fd("0x", 1);
	if (!flags[ALIGN])
		ft_put_spaces(res - len - 2, flags, 1);
	if (!flags[ZERO])
		ft_putstr_fd("0x", 1);
	if (flags[DOT] && flags[PRCSN] > (ft_plen(pointer, flags) - 2))
		ft_put_zeros(len - ft_plen(pointer, flags));
	if (!(flags[DOT] && !flags[PRCSN] && !pointer))
		ft_put_pointer(pointer);
	if (flags[ALIGN])
		ft_put_spaces(res - len - 2, flags, 1);
	return (res);
}
