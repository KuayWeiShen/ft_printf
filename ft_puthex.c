/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthex.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wkuay <wkuay@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/31 17:48:59 by wkuay             #+#    #+#             */
/*   Updated: 2026/10/31 20:53:10 by wkuay            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_puthex(unsigned long long nbr, char format_char)
{
	int		count;
	long	guard_ret;
	char	*hex;

	count = 0;
	guard_ret = 0;
	if (format_char == 'X')
		hex = "0123456789ABCDEF";
	else
		hex = "0123456789abcdef";
	if (nbr >= 16)
	{
		guard_ret = ft_puthex(nbr / 16, format_char);
		if (guard_ret < 0)
			return (-1);
		count += guard_ret;
	}
	guard_ret = ft_putchar(hex[nbr % 16]);
	if (guard_ret < 0)
		return (-1);
	count += guard_ret;
	return (count);
}
