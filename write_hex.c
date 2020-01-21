/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write_hex.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danrodri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/16 16:58:33 by danrodri          #+#    #+#             */
/*   Updated: 2020/01/20 15:29:10 by danrodri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char *hex_lenfield(unsigned long long int hex, f_list *flags, char *base)
{
	if (flags->hh)
		return (ft_ulltoa_base((unsigned char)hex, base));
	if (flags->h)
		return (ft_ulltoa_base((unsigned short int)hex, base));
	if (flags->l)
		return (ft_ulltoa_base((unsigned long)hex, base));
	if (flags->ll)
		return (ft_ulltoa_base(hex, base));
	return (ft_ulltoa_base((int)hex, base));
}

static int hex_spaces(int len, f_list *flags)
{
	int i;

	i = 0;
	if (len < flags->prec)
		len = flags->prec;
	if (flags->htg)
		len += 2;
	if (flags->width && (flags->prec != -1 || !flags->zero))
		while (len + i < flags->width)
			i += write(1, " ", 1);
	return (i);
}

static int hex_zeros(int len, f_list *flags)
{
	int i;

	i = 0;
	if (flags->prec == -1 && flags->zero && flags->width)
		{
			if (flags->htg)
				len += 2;
			while (len + i < flags->width)
				i += write(1, "0", 1);
		}
	if (flags->prec > len)
		while (len + i < flags->prec)
			i += write(1, "0", 1);
	return (i);
}

int	write_hex(va_list vars, char cap, f_list *flags)
{
	int count;
	unsigned long long int hex;
	int hex_len;
	char *hex_str;

	count = 0;
	hex = va_arg(vars, long long int);
	if (cap == 'x')
		hex_str = hex_lenfield(hex, flags, "0123456789abcdef");
	else
		hex_str = hex_lenfield(hex, flags, "0123456789ABCDEF");
	if (!hex_str)
		return (0);
	hex_len = ft_strlen(hex_str);
	if (!flags->minus)
		count += hex_spaces(hex_len, flags);
	if (flags->htg && cap == 'x')
		count += write(1, "0x", 2);
	if (flags->htg && cap == 'X')
		count += write(1, "0X", 2);
	count += hex_zeros(hex_len, flags);
	count += write(1, hex_str, hex_len);
	if (flags->minus)
		count += hex_spaces(hex_len, flags);
	free(hex_str);
	return (count);
}
