/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_parser_utils.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danrodri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/13 15:22:32 by danrodri          #+#    #+#             */
/*   Updated: 2020/01/13 18:44:28 by danrodri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	reset_flags(l_flags *flags)
{
	flags->minus = false;
	flags->plus = false;
	flags->space = false;
	flags->htg = false;
	flags->zero = false;
	flags->ap = false;
	flags->width = 0;
	flags->prec = 0;
}
