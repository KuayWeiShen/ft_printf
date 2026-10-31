/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wkuay <wkuay@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/24 20:21:37 by wkuay             #+#    #+#             */
/*   Updated: 2026/10/31 21:35:17 by wkuay            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_put_pointer(void *ptr)
{
	int	count;
	int	guard_ret;

	if (ptr == NULL)
		return (ft_putstring("(nil)"));
	count = write (1, "0x", 2);
	if (count < 0)
		return (-1);
	guard_ret = ft_puthex((unsigned long long)ptr, 'x');
	if (guard_ret < 0)
		return (-1);
	return (count + guard_ret);
}

int	ft_print_format(char ap, va_list args)
{
	if (ap == '\0')
		return (0);
	if (ap == 'c')
		return (ft_putchar(va_arg(args, int)));
	if (ap == 's')
		return (ft_putstring(va_arg(args, char *)));
	if (ap == 'p')
		return (ft_put_pointer(va_arg(args, void *)));
	if (ap == 'd' || ap == 'i')
		return (ft_putnbr(va_arg(args, int)));
	if (ap == 'u')
		return (ft_put_unsigned_nbr(va_arg(args, unsigned int)));
	if (ap == 'x' || ap == 'X')
		return (ft_puthex(va_arg(args, unsigned int), ap));
	if (ap == '%')
		return (ft_putchar('%'));
	return (ft_putchar('%') + ft_putchar(ap));
}

int	ft_printf(const char *format, ...)
{
	va_list	args;
	size_t	i;
	long	count;
	int		guard_ret;

	if (format == NULL)
		return (-1);
	va_start(args, format);
	i = 0;
	count = 0;
	while (format[i] != '\0')
	{
		if (format[i] == '%')
		{
			if (format[i + 1] == '\0')
				return (va_end(args), -1);
			guard_ret = ft_print_format(format[++i], args);
		}
		else
			guard_ret = ft_print_format(format[i], args);
		if (guard_ret < 0)
			return (va_end(args), -1);
		count += guard_ret;
		i++;
	}
	return (va_end(args), count);
}
