/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthex.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rzimaeva <rzimaeva@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/29 18:37:55 by rzimaeva          #+#    #+#             */
/*   Updated: 2025/11/29 19:56:33 by rzimaeva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_puthex_lower(unsigned long long n)
{
	unsigned int	last_digit;
	char			hex_char;
	int				count;

	count = 0;
	if (n >= 16)
	{
		count += ft_puthex_lower(n / 16);
	}
	last_digit = n % 16;
	if (last_digit < 10)
	{
		hex_char = last_digit + 48;
	}
	else
	{
		hex_char = last_digit - 10 + 97;
	}
	count += ft_putchar(hex_char);
	return (count);
}

int	ft_puthex_upper(unsigned int n)
{
	unsigned int	last_digit;
	char			hex_char;
	int				count;

	count = 0;
	if (n >= 16)
	{
		count += ft_puthex_upper(n / 16);
	}
	last_digit = n % 16;
	if (last_digit < 10)
	{
		hex_char = last_digit + '0';
	}
	else
	{
		hex_char = last_digit - 10 + 65;
	}
	count += ft_putchar(hex_char);
	return (count);
}
