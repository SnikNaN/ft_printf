#include "ft_printf.h"

static int	ft_xlen(unsigned int num, int flags[5])
{
	int	i;

	if (flags[DOT])
		flags[ZERO] = 0;
	if (num == 0 && flags[DOT] && !flags[PRCSN])
		return (0);
	if (num == 0)
		return (1);
	i = 0;
	if (flags[SHARP])
		i = 2;
	while (num > 0)
	{
		num /= 16;
		i++;
	}
	return (i);
}

static void	ft_putnbr_x(unsigned int num, int caps)
{
	if (num < 16)
	{
		if (num < 10)
			ft_putchar_fd('0' + num, 1);
		else
		{
			if (caps)
				ft_putchar_fd('A' + num - 10, 1);
			else
				ft_putchar_fd('a' + num - 10, 1);
		}
		return ;
	}
	else
	{
		ft_putnbr_x(num / 16, caps);
		ft_putnbr_x(num % 16, caps);
	}
}

static void	ft_put_0x(int flags[8], int caps)
{
	if (flags[SHARP])
	{
		if (caps)
			ft_putstr_fd("0X", 1);
		else
			ft_putstr_fd("0x", 1);
	}
}

int	ft_print_x(unsigned int num, int flags[5], int caps)
{
	int	res;
	int	len;

	if (flags[SHARP] && num && (ft_xlen(num, flags) - 2) < flags[PRCSN])
		len = flags[PRCSN] + 2;
	else if (ft_xlen(num, flags) < flags[PRCSN])
		len = flags[PRCSN];
	else
		len = ft_xlen(num, flags);
	if (len < flags[WIDTH])
		res = flags[WIDTH];
	else
		res = len;
	if (flags[ZERO] && num)
		ft_put_0x(flags, caps);
	if (!flags[ALIGN])
		ft_put_spaces(res - len, flags, 1);
	if (!flags[ZERO] && num)
		ft_put_0x(flags, caps);
	ft_put_zeros(len - ft_xlen(num, flags));
	if (!(flags[DOT] && !flags[PRCSN] && !num))
		ft_putnbr_x(num, caps);
	if (flags[ALIGN])
		ft_put_spaces(res - len, flags, 1);
	return (res);
}
