/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   d_type.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danrodri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/24 19:26:29 by danrodri          #+#    #+#             */
/*   Updated: 2020/01/28 18:22:36 by danrodri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libftprintf.h"

static int	dec_minfieldwidth(int len, int i, t_flst *flags)
{
	int i_neg;
	int width;
	int count;
	int prec;

	count = 0;
	(i < 0) ? (i_neg = 1) : (i_neg = 0);
	(flags->width && !flags->zero) ? (width = flags->width) : (width = 0);
	(flags->prec[0] && flags->prec[1] > len) ? (prec = flags->prec[1]) : (prec = len);
	if (flags->prec[0] == -1 && !i)
		prec = 0;
	while (count + i_neg + prec < width)
		count += write(1, " ", 1);
	return (count);
}

static int	dec_writer(char *str, int len, int i, t_flst *flags)
{
	int i_count;
	int z_count;
	int z_len;

	i_count = 0;
	z_count = 0;
	z_len = 0;
	if (flags->prec[0] == -1 && !i)
		return (0);
	if (flags->width && flags->zero)
		z_len = flags->width - len;
	if (flags->prec[0] && flags->prec[1] > len)
		z_len = flags->prec[1] - len;
	if (i < 0)
		i_count += write(1, "-", 1);
	if (flags->width && flags->zero && i < 0)
		z_len--;
	while (z_count < z_len)
		z_count += write(1, "0", 1);
	while (str[i_count])
		i_count += write(1, &str[i_count], 1);
	return (i_count + z_count);
}

int			d_type(va_list vars, t_flst *flags)
{
	int				count;
	int	i;
	int				i_len;
	char			*i_str;

	count = 0;
	i = va_arg(vars, int);
	i_str = ft_itoa(i);
	if (!(i_str))
		return (0);
	(i < 0) ? (i_len = ft_strlen(i_str) - 1) : (i_len = ft_strlen(i_str));
	if (!flags->minus)
		count += dec_minfieldwidth(i_len, i, flags);
	count += dec_writer(i_str, i_len, i, flags);
	if (flags->minus)
		count += dec_minfieldwidth(i_len, i, flags);
	free(i_str);
	return (count);
}
