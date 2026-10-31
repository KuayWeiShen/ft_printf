/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wkuay <wkuay@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/31 16:47:44 by wkuay             #+#    #+#             */
/*   Updated: 2026/10/31 20:53:55 by wkuay            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putnbr(long nbr)
{
	int		count;
	long	guard_ret;

	count = 0;
	guard_ret = 0;
	if (nbr < 0)
	{
		guard_ret = ft_putchar('-');
		if (guard_ret < 0)
			return (-1);
		count += guard_ret;
		nbr = -nbr;
	}
	if (nbr > 9)
	{
		guard_ret = ft_putnbr(nbr / 10);
		if (guard_ret < 0)
			return (-1);
		count += guard_ret;
	}
	guard_ret = ft_putchar((nbr % 10) + '0');
	if (guard_ret < 0)
		return (-1);
	count += guard_ret;
	return (count);
}

//The guard return variable is to gaurd against the possibility
//of error occurring during the writing process