#include "mymath.h"

long long my_mult(long long a, long long b, long long mod)
{
	long long sum = 0;

	while (b)
	{
		if (b & 1)
		{
			sum = (sum + a) % mod;
		}

		a = (a << 1) % mod;
		b =  b >> 1;
	}

	return sum;
}

long long my_pow(long long x, long long p, long long mod)
{
	long long res = 1;

	while (p)
	{
		if (p & 1)
		{
			res = my_mult(res, x, mod);
		}

		p = p >> 1;
		x = my_mult(x, x, mod);
	}

	return res;
}