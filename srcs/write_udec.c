/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write_udec.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danrodri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/16 18:11:11 by danrodri          #+#    #+#             */
/*   Updated: 2020/01/22 17:33:41 by danrodri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char	*udec_lenfield(unsigned long long int u, f_list *flags)
{
	if (flags->hh)
		return (ft_ulltoa_base((unsigned char)u, "0123456789"));
	if (flags->h)
		return (ft_ulltoa_base((unsigned short int)u, "0123456789"));
	if (flags->l)
		return (ft_ulltoa_base((unsigned long int)u, "0123456789"));
	if (flags->ll)
		return (ft_ulltoa_base((unsigned long long int)u, "0123456789"));
	return (ft_ulltoa_base(u, "0123456789"));
}

static int	udec_width_writer(int len, f_list *flags)
{
	int i;

	i = 0;
	if (flags->ap)
		len += utils_ap_size(len);
	if (flags->prec > len)
		len = flags->prec;
	if (flags->zero && !flags->minus && flags->width && flags->prec == -1)
		while (len + i < flags->width)
			i += write(1, "0", 1);
	if ((!flags->zero || flags->prec != -1) && flags->width)
		while (len + i < flags->width)
			i += write(1, " ", 1);
	return (i);
}

static int	udec_prec_writer(int len, f_list *flags)
{
	int i;

	i = 0;
	if (flags->ap)
		len += utils_ap_size(len);
	if (flags->prec > len)
		while (len + i < flags->prec)
			i += write(1, "0", 1);
	return (i);
}

static int	udec_writer(char *str, int len, f_list *flags)
{
	int i;
	int count;

	i = 0;
	count = 0;
	if (!flags->prec && !ft_strncmp(str, "0", len))
		return (0);
	if (flags->ap)
		while (str[count])
		{
			i += write(1, &str[count], 1);
			if (!((len - count - 1) % 3) && (len - count - 1))
				i += write(1, ",", 1);
			count++;
		}
	else
		i += write(1, str, len);
	return (i);
}

int			write_udec(va_list vars, f_list *flags)
{
	int						c_written;
	int						u_len;
	unsigned long long int	u;
	char					*u_str;

	c_written = 0;
	u = va_arg(vars, long long int);
	if (!(u_str = udec_lenfield(u, flags)))
		return (0);
	u_len = ft_strlen(u_str);
	if (!flags->minus)
		c_written += udec_width_writer(u_len, flags);
	c_written += udec_prec_writer(u_len, flags);
	c_written += udec_writer(u_str, u_len, flags);
	if (flags->minus)
		c_written += udec_width_writer(u_len, flags);
	free(u_str);
	return (c_written);
}
