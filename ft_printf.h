/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danrodri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/09 18:06:43 by danrodri          #+#    #+#             */
/*   Updated: 2020/01/13 18:44:53 by danrodri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdlib.h>
# include <stdarg.h>
# include <unistd.h>
#include <stdio.h>
# include <stdbool.h>
# include "libft/libft.h"
typedef struct s_flags{
	bool minus;
	bool plus;
	bool space;
	bool htg;
	bool zero;
	bool ap;
	int width;
	int prec;
} l_flags;
int	ft_printf(char *fmt, ...);
int print_ptr(va_list arg, l_flags *flags);
int print_int(va_list arg, l_flags *flags);
int print_hex(va_list arg, int type, l_flags *flags);
int print_u(va_list arg, l_flags *flags);
int print_char(va_list arg, l_flags *flags);
int print_str(va_list arg, l_flags *flags);
int	ft_printf_parser(char *fmt, l_flags *flags, va_list arg);
int	flags_parser(char *fmt, l_flags *flags);
int width_parser(char *fmt, l_flags *flags, va_list arg);
int precision_parser(char *fmt, l_flags *flags, va_list arg);
void reset_flags(l_flags *flags);
int ft_printf_writer(char type, l_flags *flags, va_list arg);
int int_width_writer(int str_len, l_flags *flags);
int	char_width_writer(int str_len, int width);
int prec_writer(int str_len, int zeros);

#endif
