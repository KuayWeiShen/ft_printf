/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flag_padding.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wkuay <wkuay@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/21 14:10:31 by wkuay             #+#    #+#             */
/*   Updated: 2026/11/21 14:10:31 by wkuay            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int ft_actual_digit_len(int nbr, t_format *fmt)
{
    int len;
    long    n;

    if (fmt != NULL && nbr == 0 && fmt->has_precision != 0 && fmt->precision == 0)
        return (0);
    if (nbr < 0)
        n = -(long)nbr;
    else
        n = (long)nbr;
    len = 1;
    while (n >= 10)
    {
        n /= 10;
        len++;
    }
    return (len);
}

int ft_actual_str_len(char *str, t_format *fmt)
{
    int str_len;

    str_len = 0;
    if (str == NULL)
        str = "(null)";
    str_len = ft_strlen(str);
    if (fmt != NULL && fmt->has_precision != 0 && fmt->precision < str_len)
        return (fmt->precision);
    return (str_len);
}

int ft_print_hash(char ap, unsigned long long nbr, t_format *fmt)
{
    if (fmt == NULL || fmt->hash == 0 || nbr == 0)
        return (0);
    if (ap == 'x')
        return (ft_putstring("0x"));
    if (ap == 'X')
        return (ft_putstring("0X"));
    return (0);
}

void    ft_flag_prefix(char ap, t_format *fmt, long nbr)
{
    if (fmt == NULL)
        return (0);
    if (ap == 'd' || ap == 'i')
    {
        if (nbr < 0)
            return (ft_putchar('-'));
        else if (fmt->plus == 1)
            return (ft_putchar('+'));
        else if (fmt->space == 1)
            return (ft_putchar(' '));
    }
    if (ap == 'x' || ap == 'X')
        return (ft_print_hash(ap, (unsigned long long)nbr, fmt));
    return (0);
}

void    ft_flag_padding(t_format *fmt, int pad_len, int is_zero)
{
    char    pad_char;

    if (fmt == NULL || pad_len <= 0)
        return (0);
    if (is_zero != 0 && fmt->minus == 0)
        pad_char = '0';
    else
        pad_char = ' ';
    return (ft_putnchar(pad_char, pad_len));
}
