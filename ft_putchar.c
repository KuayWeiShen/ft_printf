/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wkuay <wkuay@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/25 18:31:35 by wkuay             #+#    #+#             */
/*   Updated: 2026/11/21 19:06:12 by wkuay            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putchar(int c, t_format *fmt)
{
	char	ch;
	int		count;

	ch = (char)c;
	count = write (1, &ch, 1);
	if (count < 0)
		return (-1);
	return (count);
}

int	ft_putnchar(int c, int print_count)
{
	int	count;

	count = 0;
	while (print_count > 0)
	{
		if (ft_putchar(c) < 0)
			return (-1);
		print_count--;
		count++;
	}
	return (count);
}

//The purpose of casting the int c to char is to write exactly 
//1 byte instead of standard 4-bytes of int