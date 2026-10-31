/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wkuay <wkuay@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/24 20:15:11 by wkuay             #+#    #+#             */
/*   Updated: 2026/10/31 21:10:34 by wkuay            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdlib.h>
# include <stddef.h>
# include <stdarg.h>
# include "libft/libft.h"

int	ft_put_pointer(void *ptr);
int	ft_print_format(char argument, va_list args);
int	ft_printf(const char *format, ...);
int	ft_putchar(int c);
int	ft_puthex(unsigned long long nbr, char format_char);
int	ft_putnbr(long nbr);
int	ft_put_unsigned_nbr(long nbr);
int	ft_putstring(char *str);

#endif