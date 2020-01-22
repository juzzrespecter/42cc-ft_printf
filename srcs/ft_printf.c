/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danrodri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/17 17:00:38 by danrodri          #+#    #+#             */
/*   Updated: 2020/01/22 15:31:21 by danrodri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

static void	reset_flags(f_list *flags)
{
	flags->minus = false;
	flags->plus = false;
	flags->space = false;
	flags->zero = false;
	flags->ap = false;
	flags->hh = false;
	flags->h = false;
	flags->l = false;
	flags->ll = false;
	flags->htg = false;
	flags->prec = -1;
	flags->width = 0;
}

int			ft_printf(char *fmt, ...)
{
	f_list	flags;
	va_list	vars;
	int		c_written;
	int		count;

	c_written = 0;
	count = 0;
	va_start(vars, fmt);
	while (fmt[count])
	{
		if (fmt[count] == '%')
		{
			count++;
			reset_flags(&flags);
			count += get_flags(&flags, fmt + count);
			count += get_width(&flags, fmt + count, vars);
			count += get_prec(&flags, fmt + count, vars);
			count += get_lenfield(&flags, fmt + count);
			c_written += read_specifier(fmt[count], vars, &flags, c_written);
		}
		else
			c_written += write(1, &fmt[count], 1);
		count++;
	}
	return (c_written);
}
