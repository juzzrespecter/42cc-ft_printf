#include <stdio.h>
#include "ft_printf.h"
#include <string.h>
#include <locale.h>

int main(void)
{
	int i1, i2;
	wchar_t *ls = L"b\u4567onjour";
	wchar_t lc = 4567;

	setlocale(LC_CTYPE, "UTF-8");
	i1 = ft_printf("ft: %lc, %lc\n", lc, ls[1]);
	i2 = printf("pr: %lc, %lc\n", lc, ls[1]);
	printf("pr %d, ft %d\n", i2, i1);
}
