#include "ft_printf.h"

static int	ft_dlen(int num, int flags[5])
{
	int	i;

	if (!num)
	{
		if (flags[DOT] && !flags[PRCSN])
		{
			if (flags[PLUS] || flags[SPACE])
				return (1);
			return (0);
		}
		else if (flags[PLUS] || flags[SPACE])
			return (2);
		return (1);
	}
	i = 0;
	if (num < 0 || flags[PLUS] || flags[SPACE])
		i = 1;
	while (num != 0)
	{
		num /= 10;
		i++;
	}
	return (i);
}

static void	ft_putnbr(int num)
{
	if (num < 0)
		ft_putnbr_unsigned((unsigned int)(-num));
	else
		ft_putnbr_unsigned((unsigned int)num);
}

static void	ft_put_sign(int num, int flags[8])
{
	if (num < 0)
	{
		ft_putchar_fd('-', 1);
		flags[PLUS] = 0;
		flags[SPACE] = 0;
	}
	else if (flags[PLUS])
		ft_putchar_fd('+', 1);
	else if (flags[SPACE])
		ft_putchar_fd(' ', 1);
}

static int	ft_pos(int flags[8])
{
	if (flags[PLUS] || flags[SPACE])
		return (1);
	return (0);
}

int	ft_print_d(int num, int flags[5])
{
	int	res;
	int	len;

	if (ft_dlen(num, flags) <= flags[PRCSN] && (num < 0 || ft_pos(flags)))
		len = flags[PRCSN] + 1;
	else if (ft_dlen(num, flags) < flags[PRCSN])
		len = flags[PRCSN];
	else
		len = ft_dlen(num, flags);
	if (len < flags[WIDTH])
		res = flags[WIDTH];
	else
		res = len;
	if (flags[ZERO] && !flags[DOT])
		ft_put_sign(num, flags);
	if (!flags[ALIGN])
		ft_put_spaces(res - len, flags, 1);
	if (!flags[ZERO])
		ft_put_sign(num, flags);
	ft_put_zeros(len - ft_dlen(num, flags) - (!flags[PRCSN] && ft_pos(flags)));
	if (!(flags[DOT] && !flags[PRCSN] && !num))
		ft_putnbr(num);
	if (flags[ALIGN])
		ft_put_spaces(res - len, flags, 1);
	return (res);
}
