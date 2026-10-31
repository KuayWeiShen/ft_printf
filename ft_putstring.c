/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstring.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wkuay <wkuay@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/31 15:02:07 by wkuay             #+#    #+#             */
/*   Updated: 2026/10/31 17:57:33 by wkuay            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putstring(char *str)
{
	int	len;
	int	count;

	if (str == NULL)
		str = "(null)";
	len = ft_strlen(str);
	count = write (1, str, len);
	if (count < 0)
		return (-1);
	return (count);
}
