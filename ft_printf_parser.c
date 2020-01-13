/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_parser.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danrodri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/12 15:22:48 by danrodri          #+#    #+#             */
/*   Updated: 2020/01/13 18:45:23 by danrodri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf_parser(char *fmt, l_flags *flags, va_list arg)
{
	int	count;

	count = 0;
	reset_flags(flags);
	count += flags_parser(fmt, flags);
	count += width_parser(fmt + count, flags, arg);
	count += precision_parser(fmt + count, flags, arg);
	return (count);
}

int	flags_parser(char *fmt, l_flags *flags)
{
	int count;

	count = 0;
	while (ft_strchr(" #+'-0", fmt[count]))
		{
			if (fmt[count] == '\'')
				flags->ap = true;
			if (fmt[count] == '-')
				flags->minus = true;
			if (fmt[count] == '+')
				flags->plus = true;
			if (fmt[count] == '#')
				flags->htg = true;
			if (fmt[count] == ' ')
				flags->space = true;
			if (fmt[count] == '0')
				flags->zero = true;
			count++;
		}
	return (count);
}

int	width_parser(char *fmt, l_flags *flags, va_list arg)
{
	int count;

	count = 0;
	if ((fmt[count] >= '1' && fmt[count] <= '9') || fmt[count] == '*')
		{
			if (fmt[count] >= '1' && fmt[count] <= '9')
				{
					flags->width = ft_atoi(fmt + count);
					while (ft_isdigit(fmt[count]))
						count++;
				}
			if (fmt[count] == '*')
				{
					flags->width = va_arg(arg, int);
					count++;
				}
		}
	return (count);
}

int	precision_parser(char *fmt, l_flags *flags, va_list arg)
{
	int count;

	count = 0;
	if (fmt[count] == '.')
		{
			count++;
			if (ft_isdigit(fmt[count]))
				{
					flags->prec = ft_atoi(fmt + count);
					while (ft_isdigit(fmt[count]))
						count++;
				}
			if (fmt[count] == '*')
				{
					flags->prec = va_arg(arg, int);
					count++;
				}
		}
	return (count);
}

int	ft_printf_writer(char type, l_flags *flags, va_list arg)
{
	int	c_written;

	c_written = 0;
	if (type == 'd' || type == 'i')
		c_written = print_int(arg, flags);
	if (type == 's')
		c_written = print_str(arg, flags);
	if (type == 'p')
		c_written = print_ptr(arg, flags);
	if (type == 'c')
		c_written = print_char(arg, flags);
	if (type == 'u')
		c_written = print_u(arg, flags);
	if (type == 'x' || type == 'X')
		c_written = print_hex(arg, type, flags);
	if (type == 'f')
		c_written = print_float(arg, flags);
	if (type == '%')
		{
			write(1, "%", 1);
			c_written = 1;
		}
	reset_flags(flags);
	return (c_written);
}
