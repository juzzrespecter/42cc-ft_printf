#include "ft_printf.h"

int printf_parse(char var, va_list args)
{
  if (var == 'd' || var == 'i')
    return (write_int(args));
  if (var == 'c')
    return (write_char(args));
  if (var == 's')
    return (write_str(args));
  if (var == 'x' || var == 'X')
    return (write_hex(args, var));
  if (var == 'p')
    return (write_ptr(args));
  write(1, "%", 1);
  return (1);
}
