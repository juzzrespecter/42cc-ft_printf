/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write_dec.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danrodri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/16 16:05:12 by danrodri          #+#    #+#             */
/*   Updated: 2020/01/22 14:46:53 by danrodri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char	*dec_lenfield(long long int i, f_list *flags)
{
	if (i < 0)
		i *= -1;
	if (flags->hh)
		return (ft_itoa((char)i));
	if (flags->h)
		return (ft_itoa((short)i));
	if (flags->l)
		return (ft_lltoa_base((long)i, "0123456789"));
	if (flags->ll)
		return (ft_lltoa_base(i, "0123456789"));
	return (ft_itoa(i));
}

static int	dec_spaces(int len, f_list *flags)
{
	int i;

	i = 0;
	if (flags->ap)
		len += utils_ap_size(len);
	if (flags->prec > len)
		len = flags->prec;
	if (flags->plus || flags->space)
		len++;
	if ((!flags->zero || flags->prec != -1) && flags->width)
		while (len + i < flags->width)
			i += write(1, " ", 1);
	return (i);
}

static int	dec_zeros(int len, f_list *flags)
{
	int i;

	i = 0;
	if (flags->ap)
		len += utils_ap_size(len);
	if (flags->zero && flags->prec == -1 && flags->width)
	{
		if (flags->plus || flags->space)
			len++;
		while (len + i < flags->width)
			i += write(1, "0", 1);
	}
	if (flags->prec > len)
		while (len + i < flags->prec)
			i += write(1, "0", 1);
	return (i);
}

static int	dec_writer(char *str, int len, f_list *flags)
{
	int count;
	int i;

	count = 0;
	i = 0;
	if (flags->ap)
	{
		while (str[count])
		{
			i += write(1, &str[count], 1);
			if (!((len - count - 1) % 3) && (len - count - 1))
				i += write(1, ",", 1);
			count++;
		}
	}
	else
		i += write(1, str, len);
	return (i);
}

int			write_dec(va_list vars, f_list *flags)
{
	int				count;
	long long int	i;
	int				i_len;
	char			*i_str;

	count = 0;
	i = va_arg(vars, long long int);
	if (!(i_str = dec_lenfield(i, flags)))
		return (0);
	i_len = ft_strlen(i_str);
	if (!flags->minus)
		count += dec_spaces(i_len, flags);
	if (i < 0)
		count += write(1, "-", 1);
	if (flags->plus && i > 0)
		count += write(1, "+", 1);
	if (flags->space && !flags->plus && i > 0)
		count += write(1, " ", 1);
	count += dec_zeros(i_len, flags);
	count += dec_writer(i_str, i_len, flags);
	if (flags->minus)
		count += dec_spaces(i_len, flags);
	free(i_str);
	return (count);
}
