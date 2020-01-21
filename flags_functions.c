/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flags_functions.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danrodri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/17 17:03:31 by danrodri          #+#    #+#             */
/*   Updated: 2020/01/20 14:05:01 by danrodri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int get_flags(f_list *flags, char *fmt)
{
	int count;

	count = 0;
	while (ft_strchr("#0-+ '", fmt[count]))
		{
			if (fmt[count] == '#')
				flags->htg = true;
			if (fmt[count] == '-')
				flags->minus = true;
			if (fmt[count] == '+')
				flags->plus = true;
			if (fmt[count] == '\'')
				flags->ap = true;
			if (fmt[count] == ' ')
				flags->space = true;
			if (fmt[count] == '0')
				flags->zero = true;
			count++;
		}
	return (count);
}

int get_width(f_list *flags, char *fmt, va_list vars)
{
	int count;

	count = 0;
	if (ft_isdigit(fmt[count]))
		{
			flags->width = ft_atoi(fmt);
			while (ft_isdigit(fmt[count]))
				count++;
		}
	else
		if (fmt[count] == '*')
			{
				flags->width = va_arg(vars, int);
				count++;
			}
	return (count);
}

int get_prec(f_list *flags, char *fmt, va_list vars)
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
				flags->prec = va_arg(vars, int);
				count++;
			}
		}
	return (count);
}

int get_lenfield(f_list *flags, char *fmt)
{
	if (fmt[0] == 'h')
		{
			if (fmt[1] == 'h')
				{
					flags->hh = true;
					return (2);
				}
			flags->h = true;
			return (1);
		}
	if (fmt[0] == 'l')
		{
			if (fmt[1] == 'l')
				{
					flags->ll = true;
					return (2);
				}
			flags->l = true;
			return (1);
		}
	return (0);
}

int	read_specifier(char spec, va_list vars, f_list *flags, int c_written)
{
	if (spec == 'd' || spec == 'i')
		return (write_dec(vars, flags));
	if (spec == 'x' || spec == 'X')
		return (write_hex(vars, spec, flags));
	if (spec == 'u')
		return (write_udec(vars, flags));
	if (spec == 's')
		return (write_str(vars, flags));
	if (spec == 'c')
		return (write_char(vars, flags));
	if (spec == 'p')
		return (write_ptr(vars, flags));
	if (spec == '%')
		return (write_percent(flags));
	if (spec == 'n')
		return (write_n(vars, flags, c_written));
	return (0);
}
