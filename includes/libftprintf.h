/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danrodri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/16 16:06:30 by danrodri          #+#    #+#             */
/*   Updated: 2020/01/22 17:32:44 by danrodri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFTPRINTF_H
# define LIBFTPRINTF_H
# include <stdarg.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdbool.h>
# include "libft/libft.h"

typedef struct	s_flags{
	bool	minus;
	bool	plus;
	bool	space;
	bool	zero;
	bool	ap;
	bool	h;
	bool	hh;
	bool	l;
	bool	ll;
	bool	htg;
	int		prec;
	int		width;
}				t_flst;
int				ft_printf(char *fmt, ...);
char			*ft_ulltoa_base(unsigned long long int n, char *base);
int				write_dec(va_list vars, f_list *flags);
int				write_udec(va_list vars, f_list *flags);
int				write_char(va_list vars, f_list *flags);
int				write_str(va_list vars, f_list *flags);
int				write_ptr(va_list vars, f_list *flags);
int				write_hex(va_list vars, char cap, f_list *flags);
int				write_percent(f_list *flags);
int				write_n(va_list vars, f_list *flags, int c_written);
int				get_flags(f_list *flags, char *fmt);
int				get_width(f_list *flags, char *fmt, va_list vars);
int				get_prec(f_list *flags, char *fmt, va_list vars);
int				get_lenfield(f_list *flags, char *fmt);
int				read_specifier(char spec, va_list vars, f_list *flags, int \
		c_written);
int				utils_ap_size(int len);
char			*u8_encoder(wchar_t u8char);
#endif
