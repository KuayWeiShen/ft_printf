/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstring.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wkuay <wkuay@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/31 15:02:07 by wkuay             #+#    #+#             */
/*   Updated: 2026/11/21 19:06:15 by wkuay            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_pad_str(int pad_len; int *count)
{
	int	guard_ret;

	guard_ret = ft_putnchar(' ', pad_len);
	if (guard_ret < 0)
		return (-1);
	*count += guard_ret;
	return (0)
}

int	ft_putstring(char *str, t_format *fmt)
{
	int	len;
	int	pad_len;
	int	count;
	int	guard_ret;

	if (str == NULL)
		str = "(null)";
	len = ft_actual_str_len(str, fmt);
	pad_len = 0;
	count = 0;
	if (fmt != NULL && fmt->width > len)
		pad_len = fmt->width - len;
	if ((fmt == NULL || fmt->minus == 0) 
		&& ft_pad_str(pad_str(pad_len, &count) < 0))
		return (-1);
	if (fmt == NULL || fmt->minus == 0)
		ft_pad_str(pad_len, &count);
	guard_ret = write (1, str, len);
	if (guard_ret < 0)
		return (-1);
	count += guard_ret;
	if (fmt != NULL && fmt->minus != 0)
		ft_pad_str(pad_len, count);
	return (count);
}
