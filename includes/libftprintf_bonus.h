/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danrodri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/16 16:06:30 by danrodri          #+#    #+#             */
/*   Updated: 2020/02/02 19:38:04 by danrodri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFTPRINTF_BONUS_H
# define LIBFTPRINTF_BONUS_H
# include <stdarg.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdbool.h>
#include <stdio.h>
# include "../libft/libft.h"

typedef struct	s_flst{
	bool l;
	bool ll;
	bool h;
	bool hh;
	bool	minus;
	bool	zero;
	bool plus;
	bool hashtag;
	bool space;
	int		prec[2];
	int		width;
}				t_flst;
int				ft_printf(char *fmt, ...);
int				d_type(va_list args, t_flst *flags);
int				u_type(va_list args, t_flst *flags);
int				c_type(va_list args, t_flst *flags);
int				s_type(va_list args, t_flst *flags);
int				p_type(va_list args, t_flst *flags);
int				x_type(va_list args, char cap, t_flst *flags);
int	n_type(va_list args, t_flst *flags, int len);
int				per_type(t_flst *flags);
int				flag_format(t_flst *flags, char *fmt);
int				minfieldwidth_format(t_flst *flags, char *fmt, va_list args);
int				prec_format(t_flst *flags, char *fmt, va_list args);
int	lenfield_format(t_flst *flags, char *fmt);
char			*ft_ultoa_base(unsigned long i, char *base);
char			*ft_ulltoa_base(unsigned long long i, char *base);
char			*ft_strcap(char *str);
char	*ft_lltoa(long long i);
int	dec_sign_writer(char *str, t_flst *flags);
int	dec_writer(char *str, int len, t_flst *flags);
char *dec_lenfield(va_list vars, t_flst *flags);
int	dec_minfieldwidth(int len, char *str, t_flst *flags);
int	hex_width(int len, char *str, t_flst *flags);
int	hex_writer(int len, char *hex_str, char cap, t_flst *flags);
char *hex_lenfield(va_list vars, t_flst *flags);
char *u_lenfield(va_list vars, t_flst *flags);
int	u_writer(char *str, int len, t_flst *flags);
int	u_width(int len, char *str, t_flst *flags);
int	char_width(t_flst *flags);
char		*u8_encoder(wchar_t u8char);
int	str_nullstr(t_flst *flags);
int	str_writer(char *str, int len, t_flst *flags);
	int	str_width(int len, t_flst *flags);
int wcs_writer(wchar_t *wcs, int len, t_flst *flags);
int	ft_wcslen(wchar_t *wcs);
int wcs_type(va_list vars, t_flst *flags);

#endif
