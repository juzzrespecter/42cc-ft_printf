#include "ft_printf.h"
#include <unistd.h>
#include <stdio.h>

int write_ptr(va_list args)
{
  char *base = "0123456789abcdef";
  long ptr;
  char *addr;

  ptr = (long)va_arg(args, void*);
  addr = ft_itoa_base(ptr, base);
  ft_putstr(addr);
  return (ft_strlen(addr));
}

int write_hex(va_list args, char cap)
{
  char base[17];
  int n;
  char *narray;

  n = va_arg(args, int);
  if (cap == 'X')
    ft_strlcpy(base, "0123456789ABCDEF", 17);
  else
    ft_strlcpy(base, "0123456789abcdef", 17);
  narray = ft_itoa_base(n, base);
  ft_putstr(narray);
  return (ft_strlen(narray));
}

int write_char(va_list args)
{
  char c;

  c = (char)va_arg(args, int);
  write(1, &c, 1);
  return (1);
}

int write_int(va_list args)
{
  char *d;
  int len;

  d = ft_itoa(va_arg(args, int));
  len = ft_strlen(d);
  write(1, d, len);
  free(d);
  return (len);
}

int write_str(va_list args)
{
  int len;
  char *s;

  s = va_arg(args, char *);
  len = ft_strlen(s);
  write(1, s, len);
  return (len);
}
