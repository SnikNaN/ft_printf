#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	long long int	num;

	num = n;
	if (num < 0)
	{
		ft_putchar_fd('-', fd);
		num = -num;
	}
	if (num < 10)
		ft_putchar_fd('0' + num, fd);
	else
	{
		ft_putnbr_fd((int)(num / 10), fd);
		ft_putnbr_fd((int)(num % 10), fd);
	}	
}
