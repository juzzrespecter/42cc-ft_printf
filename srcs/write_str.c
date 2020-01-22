/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write_str.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danrodri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/16 19:13:30 by danrodri          #+#    #+#             */
/*   Updated: 2020/01/22 17:33:27 by danrodri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	str_width_writer(int len, f_list *flags)
{
	int i;

	i = 0;
	if (flags->prec >= 0 && flags->prec < len)
		len = flags->prec;
	if (flags->width)
		while (len + i < flags->width)
			i += write(1, " ", 1);
	return (i);
}

static int	wcs_writer(void *str, int len, f_list *flags)
{
	int		i;
	int		count;
	char	*u8_str;

	i = 0;
	count = 0;
	if (flags->prec != -1 && flags->prec < len)
		len = flags->prec;
	if (flags->l)
	{
		while (count < len)
		{
			u8_str = u8_encoder(*((wchar_t*)str + count));
			i += write(1, u8_str, ft_strlen(u8_str));
			count++;
			free(u8_str);
		}
	}
	else
		i += write(1, str, len);
	return (i);
}

static int	ft_wcslen(wchar_t *wstr)
{
	int i;

	i = 0;
	while (wstr[i])
		i++;
	return (i);
}

int			write_str(va_list vars, f_list *flags)
{
	int		c_written;
	int		str_len;
	void	*str;

	c_written = 0;
	if (flags->l)
	{
		str = va_arg(vars, wchar_t *);
		str_len = ft_wcslen(str);
	}
	else
	{
		str = va_arg(vars, char*);
		str_len = ft_strlen(str);
	}
	if (!flags->minus)
		c_written += str_width_writer(str_len, flags);
	c_written += wcs_writer(str, str_len, flags);
	if (flags->minus)
		c_written += str_width_writer(str_len, flags);
	return (c_written);
}
