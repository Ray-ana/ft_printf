/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rzimaeva <rzimaeva@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/29 18:43:00 by rzimaeva          #+#    #+#             */
/*   Updated: 2025/11/29 20:01:13 by rzimaeva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stdint.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

int	ft_putchar(char c);
int	ft_putstr(char *str);
int	ft_putptr(void *ptr);
int	ft_putnbr(int n);
int	ft_putunbr(unsigned int n);
int	ft_puthex_lower(unsigned long long n);
int	ft_puthex_upper(unsigned int n);
int	ft_handle_specifier(char specifier, va_list ap);
int	ft_printf(const char *format, ...);

#endif