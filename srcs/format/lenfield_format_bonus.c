/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lenfield_format_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danrodri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/02 18:56:23 by danrodri          #+#    #+#             */
/*   Updated: 2020/02/03 20:01:22 by danrodri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libftprintf_bonus.h"

int	lenfield_format(t_flst *flags, char *fmt)
{
	if (fmt[0] == 'h')
	{
		if (fmt[1] == 'h')
			flags->hh = true;
		else
			flags->h = true;
	}
	if (fmt[0] == 'l')
	{
		if (fmt[1] == 'l')
			flags->ll = true;
		else
			flags->l = true;
	}
	if (flags->l || flags->h)
		return (1);
	if (flags->ll || flags->hh)
		return (2);
	return (0);
}
