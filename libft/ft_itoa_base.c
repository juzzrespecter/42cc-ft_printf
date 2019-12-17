#include "libft.h"
#include <stdlib.h>
#include <stdio.h>

static int abase(long i, char *base)
{
  int asize;
  int bsize;

  bsize = ft_strlen(base);
  asize = 0;
  if (i < 0)
    asize++;
  while (i /= bsize)
      asize++;
  asize++;
  return (asize);
}

char *ft_rev_array(char *array)
{
  char aux;
  int i;
  int imax;

  i = 0;
  imax = ft_strlen(array) - 1;
  while (i < imax / 2)
    {
      aux = array[i];
      array[i] = array[imax - i];
      array[imax - i] = aux;
      i++;
    }
  return (array);
}

char *ft_itoa_base(long i, char *base)
{
  char *a;
  size_t cont;
  size_t asize;
  size_t bsize;

  bsize = ft_strlen(base);
  asize = abase(i, base);
  if (!(a = malloc(sizeof(char) * (asize + 1))))
    return (NULL);
  cont = 0;
  if (i < 0)
    {
      a[cont] = '-';
      i *= -1;
      cont++;
    }
  while (cont < asize)
    {
      a[cont] = base[i % bsize];
      i /= bsize;
      cont++;
    }
  a[cont] = 0;
  ft_rev_array(a);
  return (a);
}
