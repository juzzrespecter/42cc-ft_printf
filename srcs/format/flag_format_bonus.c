/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flag_format.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danrodri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/24 18:46:51 by danrodri          #+#    #+#             */
/*   Updated: 2020/02/01 21:05:25 by danrodri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libftprintf_bonus.h"

int	flag_format(t_flst *flags, char *fmt)
{
	int count;

	count = 0;
	while (ft_strchr("0- +#", fmt[count]))
	{
		if (fmt[count] == '-')
			flags->minus = true;
		if (fmt[count] == '0')
			flags->zero = true;
		if (fmt[count] == '+')
			flags->plus = true;
		if (fmt[count] == ' ')
			flags->space = true;
		if (fmt[count] == '#')
			flags->hashtag = true;
		count++;
	}
	if (flags->minus)
		flags->zero = false;
	if (flags->plus)
		flags->space = false;
	return (count);
}
