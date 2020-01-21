/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write_percent.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danrodri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/17 16:27:07 by danrodri          #+#    #+#             */
/*   Updated: 2020/01/20 14:10:55 by danrodri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int write_percent(f_list *flags)
{
	int count;

	count = 0;
	if ((!flags->minus && !flags->zero) && flags->width)
		while (count + 1 < flags->width)
			count += write(1, " ", 1);
	if (!flags->minus && flags->zero && flags->width)
		while (count + 1 < flags->width)
			count += write(1, "0", 1);
	count += write(1, "%", 1);
	if (flags->minus && flags->width)
		while (count < flags->width)
			count += write(1, " ", 1);
	return (count);
}

int write_n(va_list vars, f_list *flags, int count)
{
	void *ptr;

	ptr = va_arg(vars, void*);
	if (flags->hh)
		{
			*(char*)ptr = count;
			return (0);
		}
	if (flags->h)
		{
			*(short int*)ptr = count;
			return (0);
		}
	if (flags->l)
		{
			*(long int*)ptr = count;
			return (0);
		}
	if (flags->ll)
		{
			*(long long int*)ptr = count;
			return (0);
		}
	*(int *)ptr = count;
	return (0);
}
