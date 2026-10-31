/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_unsigned_nbr.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wkuay <wkuay@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/31 17:34:12 by wkuay             #+#    #+#             */
/*   Updated: 2026/10/31 20:52:59 by wkuay            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_put_unsigned_nbr(long nbr)
{
	int		count;
	long	guard_ret;

	count = 0;
	guard_ret = 0;
	if (nbr > 9)
	{
		guard_ret = ft_put_unsigned_nbr(nbr / 10);
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

//Separating this as another helper function to keep signed
//and unsigned cast