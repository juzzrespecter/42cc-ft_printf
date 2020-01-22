/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write_char.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danrodri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/17 16:18:59 by danrodri          #+#    #+#             */
/*   Updated: 2020/01/22 17:47:12 by danrodri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	char_width_writer(f_list *flags)
{
	int i;

	i = 0;
	if (flags->width)
		while (i + 1 < flags->width)
			i += write(1, " ", 1);
	return (i);
}

static int	u8char_writer(wchar_t u8char)
{
	char	*u8char_str;
	int		i;

	if (!(u8char_str = u8_encoder(u8char)))
		return (0);
	i = write(1, u8char_str, ft_strlen(u8char_str));
	free(u8char_str);
	return (i);
}

int			write_char(va_list vars, f_list *flags)
{
	wchar_t	c;
	int		count;

	count = 0;
	c = va_arg(vars, int);
	if (!flags->minus)
		count += char_width_writer(flags);
	if (flags->l)
		count += u8char_writer(c);
	else
		count += write(1, &c, 1);
	if (flags->minus)
		count += char_width_writer(flags);
	return (count);
}
