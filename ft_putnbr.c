/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wkuay <wkuay@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/31 16:47:44 by wkuay             #+#    #+#             */
/*   Updated: 2026/11/21 21:30:38 by wkuay            ###   ########.fr       */
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

static int	ft_get_prefix_len(long nbr, t_format *fmt)
{
	if (num < 0 || fmt->plus != 0 || fmt->space != 0)
		return (1);
	return (0);
}

static int	ft_addnchar(char c, int n, int *count)
{
	int	guard_ret;

	guard_ret = ft_putnchar(c, n);
	if (guard_ret < 0)
		return (-1);
	*count += guard_ret;
	return (0);
}

int	ft_print_int(long nbr, t_format *fmt)
{
	int	digits;
	int	prec_zeros;
	int	pad_len;
	int	count;
	int	guard_ret;

	digits = ft_actual_digit_len(nbr, fmt);
	prec_zeros = 0;
	if (fmt->has_precision != 0 && fmt->precision > digits)
		prec_zeros = fmt->precision - digits;
	pad_len = fmt->width - (ft_get_prefix_len(nbr, fmt) + prec_zeros + digits);
	if (pad_len < 0)
		pad_len = 0;
	count = 0;
	if (fmt->minus == 0 && !(fmt->zero != 0 && fmt->has_precision == 0))
		ft_addnchar(' ', pad_len, &count);
	guard_ret = ft_flag_prefix('d', fmt, (long)nbr);
	if (guard_ret < 0)
		return (-1);
	count += guard_ret;
	if (fmt->minus == 0 && fmt->zero != 0 && fmt->has_precision == 0)
		ft_addnchar('0', pad_len, &count);
	guard_ret = ft_putnchar('0', prec_zeros);
	if (guard_ret < 0)
		return (-1);
	count += guard_ret;
}

//The guard return variable is to guard against the possibility
//of error occurring during the writing process