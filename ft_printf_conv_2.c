/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_conv_2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danrodri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/09 20:21:05 by danrodri          #+#    #+#             */
/*   Updated: 2020/01/13 17:57:00 by danrodri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int print_u(va_list arg, l_flags *flags)
{
	unsigned int u;
	int u_len;
	int c_written;
	char *a;

	c_written = 0;
	u = (unsigned int)va_arg(arg, int);
	if (!(a = ft_itoa_base(u, "0123456789")))
		return (0);
	u_len = ft_strlen(a);
	if (!flags->minus && flags->width)
		c_written += int_width_writer(u_len, flags);
	if (flags->prec > u_len)
		c_written += prec_writer(u_len, flags->prec);
	c_written += write(1, a, u_len);
	if (flags->minus && flags->width)
		c_written += int_width_writer(u_len, flags);
	free(a);
	return (c_written);
}

int	print_float(va_list arg, l_flags *flags)
{
	double	f;
	int c_written;

	c_written = 0;
	f = va_arg(arg, double);
}

int printf_scinot(va_list arg, l_flags *flags)
{

}
