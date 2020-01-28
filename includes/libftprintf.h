/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danrodri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/16 16:06:30 by danrodri          #+#    #+#             */
/*   Updated: 2020/01/27 19:16:49 by danrodri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFTPRINTF_H
# define LIBFTPRINTF_H
# include <stdarg.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdbool.h>
# include "../libft/libft.h"
#include <stdio.h>

typedef struct	s_flst{
	bool	minus;
	bool	zero;
	int		prec[2];
	int		width;
}				t_flst;
int				ft_printf(char *fmt, ...);
int				d_type(va_list args, t_flst *flags);
int				u_type(va_list args, t_flst *flags);
int				c_type(va_list args, t_flst *flags);
int				s_type(va_list args, t_flst *flags);
int				p_type(va_list args, t_flst *flags);
int				xX_type(va_list args, char cap, t_flst *flags);
int				per_type(t_flst *flags);
int				flag_format(t_flst *flags, char *fmt);
int				minfieldwidth_format(t_flst *flags, char *fmt, va_list args);
int				prec_format(t_flst *flags, char *fmt, va_list args);
char *ft_ultoa_base(unsigned long i, char *base);
char *ft_strcap(char *str);
#endif
