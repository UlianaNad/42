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

int	check_conversion(char format, va_list args)
{
	if(specifier == 'c')
		return (ft_putchar(va_arg(*args, int)));
}

int	ft_putchar(char c)
{
	int	result;

	result = write(1, &c, 1);
	if (result == -1)
		return (-1);
	return (1); 
}

int ft_printf(const char *, ...)
{
	va_list args;
	
	va_start(args, format);
	if (!format)
		return (-1);
	while (*format)
	{
		if(*format == '%' && *(format + 1))
		{
			format++;
			count +=check_conversion(*format, args, &count);
		}
		else
		{
			count += ft_putchar(*format, &count);
		}
	format++;
	}
	va_end(args);
	return (count);
}

