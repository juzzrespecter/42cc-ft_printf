#include "includes/libftprintf.h"
#include <stdio.h>
#include <locale.h>
#include <limits.h>
int main(void)
{
	int i1, i2;

	i1 = printf("pr %*.*s\n",0,-5, "Hello");
	i2 = ft_printf("ft %*.*s\n",0,-5, "Hello");

	printf("pr %d, ft %d\n", i1, i2);
}
