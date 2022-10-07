#include "prime_tests.h"
#include "mymath.h"

#include <stdio.h>
#include <math.h>

void factor(long long n, long long *s, long long *d)
{
	*d = n - 1;

	while ((*d) % 2 == 0)
	{
		(*d) /= 2;
		(*s) += 1;
	}
}

int rabin_miller(long long n)
{
	long long s = 0, d = 0;
	long long a = 0, bound = 0;
	long long x = 0;
	long long i = 0;
	long long flag = 0;

	if (n == 2)
		return 1;

	if (n % 2 == 0 || n < 2)
		return 0;

	factor(n, &s, &d);

	bound = (long long)round(2 * log(n) * log(n));

	if (bound > n - 2)
		bound = n - 2; 

	for (a = 2; a < bound; ++a)
	{
		x = my_pow(a, d, n);

		if (x == 1 || x == n - 1)
			continue;

		flag = 1;

		for (i = 0; i < s - 1; ++i)
		{
			x = my_pow(x, 2, n);
			if (x == n - 1)
			{
				flag = 0;
				break;
			}
		}

		if (flag)
			return 0;
	}

	return 1;
}