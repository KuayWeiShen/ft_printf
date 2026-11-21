#include "ft_printf.h"

void ft_init_format(t_format *fmt)
{
    if (fmt == NULL)
        return ;
    ft_bzero(fmt, sizeof(*fmt));
}

static void ft_parse_boolean_flags(const char *format, size_t *i, t_format *fmt)
{
    if (format == NULL || i == NULL || fmt == NULL)
        return ;
    while (format[*i] == '-' || format[*i] == '0' || format[*i] == '#'
        || format[*i] == ' ' || format[*i] == '+')
    {
        if (format[*i] == '-')
            fmt->minus = 1;
        else if (format[*i] == '0')
            fmt->zero = 1;
        else if (format[*i] == '#')
            fmt->hash = 1;
        else if (format[*i] == ' ')
            fmt->space = 1;
        else if (format[*i] == '+')
            fmt->plus = 1;
        (*i)++;
    }
}

static void ft_parse_number(const char *format, size_t *i, int *len)
{
    int digit;

    if (format == NULL || i == NULL || len == NULL)
        return ;
    while (format[*i] >= '0' && format[*i] <= '9')
    {
        digit = format[*i] - '0';
        if (*len <= MY_INT_MAX - digit / 10)
            *len = (*len * 10) + digit;
        (*i)++;
    }
}

void    ft_parse_flags(const char *format, size_t *i, t_format *fmt)
{
    if (format == NULL || i == NULL || fmt == NULL)
        return ;
    ft_parse_boolean_flags(format, i , fmt);
    ft_parse_number(format, i, &fmt->width);
    if (format[*i] = '.')
    {
        fmt->has_precision = 1;
        (*i)++;
        ft_parse_number(format, i, &fmt->precision);
    }
}
