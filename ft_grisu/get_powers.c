/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_powers.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danrodri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/05 18:34:19 by danrodri          #+#    #+#             */
/*   Updated: 2020/02/07 21:27:25 by danrodri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include "minilib.h"
#include <math.h>
#include <float.h>
#include <string.h>

unsigned long get_mantissa(unsigned long power)
{
	return ((power & 0xFFFFFFFFFFFFFull) | 0x10000000000000);
}

int get_exp(unsigned long power)
{
	return ((power >> 52) - 1023);
}


int main(int argc, char **argv)
{
	int mfd;
	int kmin = -307;
	int kmax = 308;
	int k;
	char *txt;
	char *c_power;
	char *f = "\n};\nstatic const int e_ten_powers[] = {\n";
	double d_power;
	unsigned long m_power;
	char *d = "#ifndef TEN_POWERS_H\n# define TEN_POWERS_H\nstatic const unsigned long m_ten_powers[] = {\n";

	printf("EEH! min exp: %d, max exp: %d, ndm: %d\n", DBL_MIN_10_EXP, DBL_MAX_10_EXP, DBL_MANT_DIG);

	printf("%lu, %lu\n", sizeof(unsigned long), sizeof(double));
	if (argc != 2)
		{
			write(1, ">:-(\n", 5);
			return(0);
		}
	txt = argv[1];
	k = kmin;
	if ((mfd = open(txt, O_WRONLY)) < 1 )
		{
			write(1, ">:-(\n", 5);
			return(0);
		}
	write(mfd, d, strlen(d));
	while (k < kmax)
		{
			d_power = pow(10, k);
			m_power = get_mantissa(*(unsigned long *)&d_power);
			c_power = ft_ultoa_base(m_power, "0123456789abcdef");
			write(mfd, "0x", 2);
			write(mfd, c_power, strlen(c_power));
			k++;
			if (k < kmax)
			write(mfd, ",\n", 2);
		}
	k = kmin;
	write(mfd, f, strlen(f));
	while (k < kmax)
		{
			d_power = pow(10, k);
			m_power = get_exp(*(unsigned long *)&d_power);
			c_power = ft_itoa(m_power);
			write(mfd, c_power, strlen(c_power));
			k++;
			if (k < kmax)
			write(mfd, ",\n", 2);
		}
	write(mfd, "\n};\n#endif\n", 11);
}
