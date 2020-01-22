/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write_ptr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danrodri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/16 19:02:55 by danrodri          #+#    #+#             */
/*   Updated: 2020/01/20 13:07:35 by danrodri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int ptr_width_writer(int len, f_list *flags)
{
	int i;

	i = 0;
	len += 2;
	if (flags->width)
		while (len + i < flags->width)
			i += write(1, " ", 1);
	return (i);
}

int	write_ptr(va_list vars, f_list *flags)
{
	int c_written;
	int addr_len;
	unsigned long addr;
	char *addr_str;

	c_written = 0;
	addr = va_arg(vars, unsigned long);
	addr_str = ft_ulltoa_base(addr, "0123456789abcdef");
	addr_len = ft_strlen(addr_str);
	if (!flags->minus)
		c_written += ptr_width_writer(addr_len, flags);
	c_written += write(1, "0x", 2);
	c_written += write(1, addr_str, addr_len);
	if (flags->minus)
		c_written += ptr_width_writer(addr_len, flags);
	free(addr_str);
	return (c_written);
}
