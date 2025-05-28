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

#include "libftprintf.h"
#include <stdio.h> 

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

	address = (unsigned long) ptr;
	count = 0;
	
	if (address == 0)
		count += ft_putstr("(nil)");
	else
	{
		count += ft_putstr("0x");
		count += ft_unlong_puthex(address, 'x');
	}	
	return (count);
}

int	ft_putnbr(int n)
{
	int	res;
	char	digit;

	res = 0;	
	if(n == -2147483648)
	{
		res += ft_putstr("-2147483648");
		return (res);
	}
	if (n < 0)
	{
		res += ft_putchar('-');
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
	int	result;

	count = 0;
	if (format == 'x')
		hex = "0123456789abcdef";
	else
		hex = "0123456789ABCDEF";
	if (n >= 16)
	{
		result = ft_puthex(n / 16, format);
		if (result == -1)
			return (-1);
		count +=result;
	}
	result = ft_putchar(hex[n % 16]);
	if (result == -1)
		return (-1);
	count += result;
	return (count);
}

int	ft_unlong_puthex(unsigned long n, char format)
{
	char    *hex;
	int     count;
	
	count = 0;
	if (format == 'x')
		hex = "0123456789abcdef";
	else
		hex = "0123456789ABCDEF";
	if (n >= 16)
		count = ft_unlong_puthex(n / 16, format);
	count += ft_putchar (hex[n % 16]);
	return (count);
}

int	ft_putuns(unsigned int n)
{
	int	count;
	char	digit;

	count = 0;
	if (n > 9)
		count += ft_putuns(n/10);
	digit = n % 10 + '0';
	count += ft_putchar(digit);
	return (count);
}

int	check_conversion(char specifier, va_list *args)
{
	int	result;

	if(specifier == 'c')
		result = ft_putchar(va_arg(*args, int));
	else if (specifier == 's')
		result = ft_putstr(va_arg(*args, char *));
	else if (specifier == 'p')
		result = ft_putptr(va_arg(*args, void *));
	else if (specifier == 'd' || specifier == 'i')
		result = ft_putnbr(va_arg(*args, int));
	else if (specifier == 'u')
		result = ft_putuns(va_arg(*args, unsigned int));
	else if (specifier == 'X' || specifier == 'x')
		result = ft_puthex (va_arg (*args, unsigned int), specifier);
	else if (specifier == '%')
		result = ft_putchar('%');
	else result = 0;
	
	if (result == -1)
	    return (-1);
	return (result);
}

int	libftprintf(const char *format, ...)
{
	va_list args;
	int 	count;
	int	result;
	
	va_start(args, format);
	count = 0;
	if (!format)
		return (-1);
	while (*format)
	{
		if(*format == '%' && *(format + 1))
		{
			format++;
			result = check_conversion(*format, &args);
			if (result == -1)
				return (-1);
			count += result;
			
		}
		else
		{
			result = write(1, format, 1);
			if (result == -1)
            			return (-1);
        		count += result;
			format++;
		}
	}
	va_end(args);
	return (count);
}
