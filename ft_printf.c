/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rzimaeva <rzimaeva@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/29 18:42:26 by rzimaeva          #+#    #+#             */
/*   Updated: 2025/11/29 20:16:38 by rzimaeva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdarg.h>
#include <unistd.h>

int	ft_handle_specifier(char specifier, va_list ap)
{
	int	count;

	count = 0;
	if (specifier == 'c')
		count += ft_putchar(va_arg(ap, int));
	else if (specifier == 's')
		count += ft_putstr(va_arg(ap, char *));
	else if (specifier == 'd' || specifier == 'i')
		count += ft_putnbr(va_arg(ap, int));
	else if (specifier == 'u')
		count += ft_putunbr(va_arg(ap, unsigned int));
	else if (specifier == 'x')
		count += ft_puthex_lower(va_arg(ap, unsigned int));
	else if (specifier == 'X')
		count += ft_puthex_upper(va_arg(ap, unsigned int));
	else if (specifier == 'p')
		count += ft_putptr(va_arg(ap, void *));
	else if (specifier == '%')
		count += ft_putchar('%');
	return (count);
}

int	ft_printf(const char *format, ...)
{
	va_list	ap;
	int		i;
	int		count;

	i = 0;
	count = 0;
	va_start(ap, format);
	while (format[i])
	{
		if (format[i] == '%')
		{
			i++;
			count += ft_handle_specifier(format[i], ap);
		}
		else
		{
			count += ft_putchar(format[i]);
		}
		i++;
	}
	va_end(ap);
	return (count);
}
