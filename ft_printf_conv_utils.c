/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_conv_utils.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danrodri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/12 18:02:00 by danrodri          #+#    #+#             */
/*   Updated: 2020/01/13 17:32:53 by danrodri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	int_width_writer(int str_len, l_flags *flags)
{
	int i;

	i = 0;
	if(!flags->prec && flags->zero)
		{
			while (str_len + i < flags->width)
			{
				write (1, "0", 1);
				i++;
			}
		}
	else
		{
			if (flags->prec > str_len)
				str_len = flags->prec;
			while (str_len + i < flags->width)
				{
					write(1, " ", 1);
					i++;
				}
		}
	return (i);
}

int	char_width_writer(int str_len, int width)
{
	int i;

	i = 0;
	while (str_len + i > width)
		{
			write(1, " ", 1);
			i++;
		}
	return (i);
}

int	prec_writer(int str_len, int zeros)
{
	int i;

	i = 0;
	while (str_len + i < zeros)
		{
			write (1, "0", 1);
			i++;
		}
	return (i);
}
