/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shonakam <shonakam@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/04 03:57:16 by shonakam          #+#    #+#             */
/*   Updated: 2025/02/27 04:14:53 by shonakam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static ssize_t	handle_conversion(va_list ap, char specifier, int fd)
{
	ssize_t	result;

	if (specifier == 'c')
		result = ft_putchar_fd(va_arg(ap, int), fd);
	else if (specifier == 's')
		result = ft_putstr_fd(va_arg(ap, char *), fd);
	else if (specifier == 'd' || specifier == 'i')
		result = ft_putnbr_fd(va_arg(ap, int), fd);
	else if (specifier == 'u')
		result = ft_put_unsigned_nbr(va_arg(ap, unsigned int), fd);
	else if (specifier == 'x' || specifier == 'X')
		result = ft_puthex(va_arg(ap, unsigned int), specifier, fd);
	else if (specifier == 'p')
		result = ft_putptr_fd((uintptr_t)va_arg(ap, void *), fd);
	else if (specifier == '%')
		result = ft_putchar_fd('%', fd);
	else
		return (-1);
	return (result);
}

int ft_vdprintf(int fd, const char *format, va_list ap)
{
	ssize_t	count;
	ssize_t	result;
	size_t	i;

	if (!format)
		return (-1);
	i = 0;
	count = 0;
	while (format[i])
	{
		if (format[i] == '%')
			result = handle_conversion(ap, format[++i], fd);
		else
			result = ft_putchar_fd(format[i], fd);
		if (result < 0)
			return (-1);
		count += result;
		if (format[i])
			i++;
	}
	return (count);
}

int	ft_printf(const char *format, ...)
{
	va_list	ap;
	int		count;

	va_start(ap, format);
	count = ft_vdprintf(STDOUT_FILENO, format, ap);
	va_end(ap);
	return (count);
}

int	ft_dprintf(int fd, const char *format, ...)
{
	va_list	ap;
	int		count;

	va_start(ap, format);
	count = ft_vdprintf(fd, format, ap);
	va_end(ap);
	return (count);
}
