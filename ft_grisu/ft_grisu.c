#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <math.h>
#include "../libft/libft.h"
#include "ten_powers.h"
#include "minilib.h"
# define M32 0xffffffff
# define D1LOG210 0.3012999566398114
# define TEN7 10000000

typedef struct s_diyfloat
{
	unsigned long mantissa;
	int exponent;
}	t_diyfloat;

t_diyfloat f_to_ft(unsigned long f)
{
	char * fs;
	// decode the floating point number
	t_diyfloat ft_float;

	ft_float.mantissa = (f & 0xFFFFFFFFFFFFFull) | 0x10000000000000;
	ft_float.exponent = (f >> 52) - 1023;
	fs = ft_ultoa_base(ft_float.mantissa, "01");
	printf("====check====\n\t f = %s\n\t mantissa = %ld\n\t exp = %d\n\n", fs, f, ft_float.exponent);
	return (ft_float);
}

char *ft_float_specval(unsigned long mantissa)
{
	if (mantissa == 0)
		return ("inf");
	else
		return ("NaN");
}

t_diyfloat multiply(t_diyfloat a, t_diyfloat b)
{
	unsigned long a1b1;
	unsigned long a1b2;
	unsigned long a2b1;
	unsigned long a2b2;
	t_diyfloat r;

	a1b1 = (a.mantissa << 32) * (b.mantissa << 32);
	a1b2 = (a.mantissa << 32) * (b.mantissa & M32);
	a2b1 = (a.mantissa & M32) * (b.mantissa << 32);
	a2b2 = (a.mantissa & M32) * (b.mantissa & M32);
	r.mantissa = a1b1 + (a1b2 >> 32) + (a2b1 >> 32) + \
		(((a2b2 >> 32) + (a1b2 & M32) + (a2b1 & M32)) + (1U << 31));
	r.exponent = a.exponent + b.exponent + 64;
	return (r);
}

int ft_ceil(double k)
{
	printf("k = %lf\n", k);
	if (k >= 0)
		{
			if (k > (int)k)
				return ((int)k + 1);
		}
	return ((double)(int)k);
}

int get_k(int e, int alpha, int gamma)
{
	(void)gamma;
	printf("k : %lf\n",ceil((alpha - e + 63) * D1LOG210));
	return (ceil((alpha - e + 63) * D1LOG210));
}

t_diyfloat cached_power(int k)
{
	//gets the power from a previously declared array
	//(on a .h?)
	t_diyfloat power;

	k += 307;
	power.mantissa = m_ten_powers[k];
	power.exponent = e_ten_powers[k];
	return (power);
}

void cut(t_diyfloat D, unsigned int diy_f[3])
{
	unsigned long temp = D.mantissa / (TEN7 >> D.exponent);
	diy_f[0] = temp / TEN7;
	diy_f[1] = temp % TEN7;
	diy_f[2] = (D.mantissa % (TEN7 >> D.exponent)) << D.exponent;
}

char *ft_grisu(double f)
{
	// grisu implementation
	//
	// set boundaries
	// conversion f -> ftfloat
	// find cached power
	// product
	// digit lenght
	// output (myfloat)
	t_diyfloat ft_float;
	unsigned int diy_f[3];
	t_diyfloat tenpower, D;
	int alpha = 3, gamma = 0, mk;

	ft_float = f_to_ft(*(unsigned long *)&f);
	if (ft_float.exponent == 0x7ff)
		return (ft_float_specval(ft_float.mantissa));
	mk = get_k(ft_float.exponent + 64, alpha, gamma);
	tenpower = cached_power(mk);
	D = multiply(ft_float, tenpower);
	cut(D, diy_f);
	printf("grisu: %u%07u%07ue%d\n", diy_f[0], diy_f[1], diy_f[2], -mk);
	return ("test");
	}




/*void test(unsigned long f)
{
	unsigned long a = f;
	unsigned long b = f;

	write(1, "check\n", 6);
	b = (b & 0x7ff0000000000000);
	a = (a & 0xfffffffffffff) | b;
	printf("%lf\n", (double)a);
	}*/

int main()
{
	double f = 1;
	char *test;

	printf("printf: %lf\n", f);
	test = ft_grisu(f);
	//	char *myfloat;
	//myfloat = ft_grisu(f);

}
