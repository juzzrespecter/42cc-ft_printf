#include "ft_printf.h"

int ft_printf(char *fmt, ...)
{
  va_list args;
  int i;
  int c_printed;

  va_start(args, fmt);
  i = 0;
  c_printed = 0;
  while (fmt[i])
    {
      if (fmt[i] == '%')
        {
          i++;
          c_printed += printf_parse(fmt[i], args);
        }
      else
        {
          write(1, &fmt[i], 1);
          c_printed++;
        }
      i++;
    }
  return (c_printed);
}
