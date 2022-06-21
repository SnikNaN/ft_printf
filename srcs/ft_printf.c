#include "ft_printf.h"

static int	ft_spec(const char spec, va_list *ap, int flags[8])
{
	char	*str;

	if (spec == '%')
		return (ft_print_c('%', flags));
	if (spec == 'c')
		return (ft_print_c((char)va_arg(*ap, int), flags));
	if (spec == 's')
	{
		str = va_arg(*ap, char *);
		if (str)
			return (ft_print_s(str, flags));
		return (ft_print_s("(null)", flags));
	}
	if (spec == 'x')
		return (ft_print_x(va_arg(*ap, unsigned int), flags, 0));
	if (spec == 'X')
		return (ft_print_x(va_arg(*ap, unsigned int), flags, 1));
	if (spec == 'u')
		return (ft_print_u(va_arg(*ap, unsigned int), flags));
	if (spec == 'd' || spec == 'i')
		return (ft_print_d(va_arg(*ap, int), flags));
	if (spec == 'p')
		return (ft_print_p((unsigned long long)va_arg(*ap, void *), flags));
	return (0);
}

static int	ft_read_width(const char *str, int *i, int flags[8])
{
	while (ft_isdigit(str[*i]))
	{
		flags[WIDTH] = flags[WIDTH] * 10 + str[*i] - '0';
		(*i)++;
	}
	if (!str[*i])
		return (1);
	return (0);
}

static int	ft_read_prcsn(const char *str, int *i, int flags[8])
{
	if (str[*i] == '.')
	{
		flags[DOT] = 1;
		(*i)++;
		while (ft_isdigit(str[*i]))
		{
			flags[PRCSN] = flags[PRCSN] * 10 + str[*i] - '0';
			(*i)++;
		}
		if (flags[PRCSN] < 0)
			flags[PRCSN] = 0;
	}
	if (!str[*i])
		return (1);
	return (0);
}

static int	ft_parse(const char *str, int *i, va_list *ap)
{
	int	flags[8];

	ft_init_arr(flags);
	while (ft_is_flag(str[*i]))
	{
		if (str[*i] == '-')
			flags[ALIGN] = 1;
		else if (str[*i] == '0')
			flags[ZERO] = 1;
		else if (str[*i] == '+')
			flags[PLUS] = 1;
		else if (str[*i] == '#')
			flags[SHARP] = 1;
		else if (str[*i] == ' ')
			flags[SPACE] = 1;
		(*i)++;
	}
	if (ft_read_width(str, i, flags))
		return (0);
	if (ft_read_prcsn(str, i, flags))
		return (0);
	if (flags[ALIGN])
		flags[ZERO] = 0;
	return (ft_spec(str[*i], ap, flags));
}

int	ft_printf(const char *format, ...)
{
	int		i;
	int		ret_value;
	va_list	ap;

	va_start(ap, format);
	i = 0;
	ret_value = 0;
	while (format && format[i])
	{
		if (format[i] == '%')
		{
			i++;
			ret_value += ft_parse(format, &i, &ap);
			if (format[i])
				i++;
		}
		else
		{
			ft_putchar_fd(format[i], 1);
			i++;
			ret_value++;
		}
	}
	va_end(ap);
	return (ret_value);
}
