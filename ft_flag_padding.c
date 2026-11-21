#include "ft_printf.h"

int ft_actual_digit_len(int num, t_format *fmt)
{
    int len;
    long    n;

    if (fmt != NULL && fmt->has_precision != 0 && fmt->precision == 0)
        return (0);
    if (n < 0)
        n = -(long)num;
    else
        n = (long)num;
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

void    ft_flag_padding(t_format *fmt)
{
    if (fmt->minus == 1)
        ft_putchar('-');
    else if (fmt->zero == 1)
    if (fmt->hash == 1)
    if (fmt->space == 1)
    if (fmt->plus == 1)
        ft_putchar('+');
}