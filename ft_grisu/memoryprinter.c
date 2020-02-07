#include <stdio.h>
#include <string.h>

char *rev(char *s);

unsigned long get_mantissa()
{
	int i;
	char d[64];
	double n = 123.345;
	*(unsigned long *)&n = (((*(unsigned long *)&n & 0xFFFFFFFFFFFFFull) | 0x10000000000000));
	i = 0;
	while (i < 64)
		{
			if (*(unsigned long *)&n & 1)
				d[i] = '1';
			else
				d[i] = '0';
			*(unsigned long *)&n >>= 1;
			i++;
		}
	d[i] = 0;
	rev(d);
	printf("%s\n", d);
	return (27);
}

unsigned long get_exp()
{
	int i;
	char d[64];
	double n = 123.345;
	int g;
	*(unsigned long *)&n = ((((*(unsigned long *)&n >> 52) & 0x7ff) - 1023));
	i = 0;
	g = *(unsigned int *)&n;
	while (i < 32)
		{
			if (g & 1)
				d[i] = '1';
			else
				d[i] = '0';
			g >>= 1;
			i++;
		}
	d[i] = 0;
	rev(d);
	printf("%s\n", d);
	return (27);
}

char *rev(char *s)
{
	int size = strlen(s);
	char aux;
	int i;

	i = 0;
	while (i < size/2)
		{
			aux = s[i];
			s[i] = s[size - (i + 1)];
			s[size - (i + 1)] = aux;
			i++;
		}
	return (s);
}

void dec_to_bin(void)
{
	int i;
	char d[64];
	double n = 123.345;

	i = 0;
	while (i < 64)
		{
			if (*(unsigned long *)&n & 1)
				d[i] = '1';
			else
				d[i] = '0';
			*(unsigned long *)&n >>= 1;
			i++;
		}
	d[i] = 0;
	rev(d);
	printf("%s\n", d);

}

int main()
{
	dec_to_bin();
	get_mantissa();
	get_exp();

	//k = get_mantissa(f);
	//dec_to_bin((void *)&f, 64);
}
