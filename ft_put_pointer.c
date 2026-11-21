/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_pointer.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wkuay <wkuay@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/01 14:50:14 by wkuay             #+#    #+#             */
/*   Updated: 2026/11/21 19:06:10 by wkuay            ###   ########.fr       */
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
