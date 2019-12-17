#ifndef FT_PRINTF_H
# define FT_PRINT_H
# include <stdlib.h>
# include <stdarg.h>
# include <unistd.h>
# include "libft/libft.h"

int ft_printf(char *fmt, ...);
int write_int(va_list arg);
int printf_parse(char var, va_list arg);
int write_char(va_list args);
int write_str(va_list args);
int write_hex(va_list args, char cap);
int write_ptr(va_list args);

#endif
