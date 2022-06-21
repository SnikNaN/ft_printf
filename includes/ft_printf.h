#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include "libft.h"

enum	e_flags
{
	ALIGN,
	WIDTH,
	DOT,
	PRCSN,
	ZERO,
	SHARP,
	PLUS,
	SPACE
};

int		ft_printf(const char *format, ...);

void	ft_init_arr(int arr[8]);
size_t	ft_is_flag(char c);

void	ft_put_spaces(int cnt, int flags[8], int is_num);
void	ft_put_zeros(int cnt);
void	ft_putnbr_unsigned(unsigned int num);

int		ft_print_c(char c, int flags[8]);
int		ft_print_s(char *str, int flags[8]);
int		ft_print_d(int num, int flags[8]);
int		ft_print_u(unsigned int num, int flags[8]);
int		ft_print_x(unsigned int num, int flags[8], int caps);
int		ft_print_p(unsigned long long pointer, int flags[8]);

#endif
