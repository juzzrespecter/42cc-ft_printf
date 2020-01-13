/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danrodri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/09 18:07:41 by danrodri          #+#    #+#             */
/*   Updated: 2020/01/12 19:35:31 by danrodri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf(char *fmt, ...)
{
	va_list arg;
	l_flags	flags;
	int			c_printed;
	int			i;

	c_printed = 0;
	i = 0;
	va_start(arg, fmt);
	while (fmt[i])
		{
			if (fmt[i] == '%')
				{
					i++;
					i += ft_printf_parser(fmt + i, &flags, arg);
					c_printed += ft_printf_writer(fmt[i], &flags, arg);
					i++;
				}
			else
				{
					write(1, &fmt[i], 1);
					i++;
					c_printed++;
				}
		}
	return (c_printed);
}
