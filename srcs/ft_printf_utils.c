#include "ft_printf.h"

size_t	ft_is_flag(char c)
{
	if (c == '0' || c == '-' || c == '+' || c == '#' || c == ' ')
		return (1);
	return (0);
}

void	ft_init_arr(int arr[8])
{
	int	i;

	i = 0;
	while (i < 8)
	{
		arr[i] = 0;
		i++;
	}
}

void	ft_put_spaces(int cnt, int flags[8], int is_num)
{
	char	c;

	c = ' ';
	if (is_num && flags[DOT])
		flags[ZERO] = 0;
	if (flags[ZERO] && !flags[ALIGN])
		c = '0';
	while (cnt > 0)
	{
		ft_putchar_fd(c, 1);
		cnt--;
	}
}

void	ft_put_zeros(int cnt)
{
	while (cnt > 0)
	{
		ft_putchar_fd('0', 1);
		cnt--;
	}
}

void	ft_putnbr_unsigned(unsigned int num)
{
	if (num < 10)
		ft_putchar_fd('0' + num, 1);
	else
	{
		ft_putnbr_unsigned(num / 10);
		ft_putnbr_unsigned(num % 10);
	}
}
