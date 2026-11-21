/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wkuay <wkuay@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/24 20:15:11 by wkuay             #+#    #+#             */
/*   Updated: 2026/11/21 19:06:09 by wkuay            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# ifndef MY_INT_MAX
#  define MY_INT_MAX 2147483647
# endif

# include <unistd.h>
# include <stdlib.h>
# include <stddef.h>
# include <stdarg.h>
# include "libft/libft.h"

int         ft_actual_digit_len(int nbr, t_format *fmt);
int         ft_actual_str_len(char *str, t_format *fmt);
int         ft_print_hash(char ap, unsigned long long nbr, t_format *fmt);
void        ft_flag_prefix(char ap, t_format *fmt, long nbr);
void        ft_init_format(t_format *fmt);
static void ft_parse_boolean_flags(const char *format, size_t *i, t_format *fmt);
static void ft_parse_number(const char *format, size_t *i, int *len);
void        ft_parse_flags(const char *format, size_t *i, t_format *fmt);
int         ft_put_pointer(void *ptr);
int         ft_print_format(char argument, va_list args);
int         ft_printf(const char *format, ...);
int         ft_putchar(int c);
int	        ft_putnchar(int c, int print_count);
int         ft_puthex(unsigned long long nbr, char format_char);
int         ft_putnbr(long nbr);
int         ft_put_unsigned_nbr(long nbr);
static int	ft_pad_str(int pad_len; int *count);
int         ft_putstring(char *str);

typedef struct s_format
{
    int minus;
    int zero;
    int hash;
    int space;
    int plus;
    int width;
    int precision;
    int has_precision;
}   t_format;

#endif