/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: unadoroz <unadoroz@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/26 10:12:07 by unadoroz          #+#    #+#             */
/*   Updated: 2025/05/27 11:14:33 by unadoroz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include <unistd.h>

int	check_conversion(char specifier, va_list *args)
{
	if(specifier == 'c')
		return (ft_putchar(va_arg(*args, int)));
	else if (specifier == 's')
		return (ft_putstr(va_arg(*args, char *)));
	else if (specifier == 'p')
		return (ft_putptr(va_arg(*args, void *)));
	else if (specifier == 'd' || specifier == 'i')
		return (ft_putnbr(va_arg(*args, int)));
	else if (specifier == 'X' || specifier == 'x')
		return (ft_puthex (va_arg (*args, unsigned int), specifier));
	else if (specifier == '%')
		return (ft_putchar('%'));
	return (0);
}

int	ft_putchar(char c)
{
	int	result;

	result = write(1, &c, 1);
	if (result == -1)
		return (-1);
	return (1); 
}

int	ft_putstr (char *str)
{
	int	i;
	int	result;

	if (!str)
		str = "(null)";
	i = 0;
	while (str[i])
	{
		result = write(1, &str[i], 1);
		if (result == -1)
			return (-1);
		i++;
	}
	return(i);
}

int	ft_putptr(void *ptr)
{
	unsigned long	address;
	int	count;
	int	res;

	address = (unsigned long) ptr;
	count = 0;
	/*res = write (1, "0x", 2);
	if (res == -1)
		return (-1);*/
	count += ft_putstr("0x");
	if (address == 0)
		count += ft_putchar('0');
	else
		count += ft_puthex(address, 'x');
	return (count);
}

int	ft_putnbr(int n)
{
	int	res;
	char	digit;
	
	if(n == -2147483648)
		res += ft_putstr("-2147483648");
		return (res);
	if (n < 0)
	{
		res += ft_putchar(1, "-", 1);
		n = -n;
	}
	if (n > 9)
		res += ft_putnbr(n/10);
	digit = n % 10 + '0';
	res += ft_putchar(digit);
	return (res);
}

int	ft_puthex(unsigned int n, char format)
{
	char	*hex;
	int	count;

	count = 0;
	if (format == 'x')
		hex = "0123456789abcdef";
	else
		hex = "0123456789ABCDEF";
	if (n > 16)
		count = ft_puthex(n / 16, format);
	count += ft_putchar (hex[n % 16]);
	return (count);
}

int	ft_printf(const char *format, ...)
{
	va_list args;
	int 	count;
	
	va_start(args, format);
	if (!format)
		return (-1);
	while (*format)
	{
		if(*format == '%' && *(format + 1))
		{
			format++;
			count +=check_conversion(*format, args);
		}
		else
		{
			count += ft_putchar(*format);
		}
	format++;
	}
	va_end(args);
	return (count);
}
