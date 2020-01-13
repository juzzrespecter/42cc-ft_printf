/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_conv.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danrodri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/09 18:08:12 by danrodri          #+#    #+#             */
/*   Updated: 2020/01/13 17:02:02 by danrodri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_char(va_list arg, l_flags *flags)
{
	char c;
	int c_written;

	c = va_arg(arg, int);
	c_written = 0;
	if (!flags->minus && flags->width)
		c_written += char_width_writer(1, flags->width);
	c_written += write(1, &c, 1);
	if (flags->minus && flags->width)
		c_written += char_width_writer(1, flags->width);
	return (c_written);
}

int print_str(va_list arg, l_flags *flags)
{
	char *str;
	int c_written;
	int	str_len;

	c_written = 0;
	str = va_arg(arg, char*);
	str_len = ft_strlen(str);
	if (flags->prec < str_len && flags->prec)
		str_len = flags->prec;
	if (!flags->minus && flags->width)
		c_written += char_width_writer(str_len, flags->width);
	c_written += write(1, str, str_len);
	if (flags->minus && flags->width)
		c_written += char_width_writer(str_len, flags->width);
	return (c_written);
}

int print_ptr(va_list arg, l_flags *flags)
{
	long int ptr;
	char *hexbase;
	char *addr;
	int addr_len;
	int c_written;

	ptr = va_arg(arg, long int);
	c_written = 0;
	hexbase = "0123456789abcdef";
	addr = ft_itoa_base(ptr, hexbase);
	addr_len = ft_strlen(addr);
	if (!flags->minus && flags->width)
		c_written += char_width_writer(addr_len + 2, flags->width);
	c_written += write(1, "0x", 2);
	c_written += write(1, addr, addr_len);
	if (flags->minus && flags->width)
		c_written += char_width_writer(addr_len + 2, flags->width);
	free(addr);
	return (c_written);
}

int print_int(va_list arg, l_flags *flags)
{
	int i;
	int i_len;
	int c_written;
	char *a;

	c_written = 0;
	i = va_arg(arg, int);
	a = ft_itoa(i);
	i_len = ft_strlen(a);
	if (!flags->minus && flags->width)
		int_width_writer(i_len, flags);
	if (flags->plus && a[0] != '-')
		c_written += write(1, "+", 1);
	if (flags->prec)
		c_written += prec_writer(i_len, flags->prec);
	c_written += write(1, a, i_len);
	if (flags->minus && flags->width)
		c_written += int_width_writer(i_len, flags);
	free(a);
	return (c_written);
}

int	print_hex(va_list arg, int type, l_flags *flags)
{
	int i;
	int hex_len;
	int c_written;
	char *hex;

	c_written = 0;
	i = va_arg(arg, int);
	if (type == 'x')
		hex = ft_itoa_base(i, "0123456789abcdef");
	else
		hex = ft_itoa_base(i, "0123456789ABCDEF");
	hex_len = ft_strlen(hex);
	if (!flags->minus && flags->width)
		c_written += int_width_writer(hex_len, flags);
	if (flags->prec)
		c_written += prec_writer(hex_len, flags->prec);
	c_written += write(1, hex, hex_len);
	if (flags->minus && flags->width)
		c_written += int_width_writer(hex_len, flags);
	free(hex);
	return (c_written);
}
