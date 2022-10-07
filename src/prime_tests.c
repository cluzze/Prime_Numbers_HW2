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

int check(long long n, long long d, long long s, long long a)
{
	long long x = 0;
	long long i = 0;
	long long flag = 0;

	x = my_pow(a, d, n);

	if (x == 1 || x == n - 1)
		return 1;

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

	return 1;
}

int rabin_miller(long long n)
{
	long long s = 0, d = 0;
	long long a = 0, bound = 0;


	if (n == 2)
		return 1;

	if (n % 2 == 0 || n < 2)
		return 0;

	factor(n, &s, &d);

	bound = (long long)round(2 * log(n) * log(n));

	if (bound > n - 2)
		bound = n - 2; 

	if (n < 2047)
		return check(n, d, s, 2);

	if (n < 1373652)
		return check(n, d, s, 2) && check(n, d, s, 3);

	if (n < 9080191)
		return check(n, d, s, 31) && check(n, d, s, 73);

	if (n < 25326001)
		return check(n, d, s, 2) && check(n, d, s, 3) && check(n, d, s, 5);

	if (n < 3215031751)
		return check(n, d, s, 2) && check(n, d, s, 3) && check(n, d, s, 5) && check(n, d, s, 7);

	if (n < 4759123141)
		return check(n, d, s, 2) && check(n, d, s, 7) && check(n, d, s, 61);

	if (n < 1122004669633)
		return check(n, d, s, 2) && check(n, d, s, 13) && check(n, d, s, 23) && check(n, d, s, 1662803);

	if (n < 2152302898747)
		return check(n, d, s, 2) && check(n, d, s, 3) && check(n, d, s, 5) && check(n, d, s, 7) && check(n, d, s, 11);

	if (n < 3474749660383)
		return check(n, d, s, 2) && check(n, d, s, 3) && check(n, d, s, 5) && check(n, d, s, 7) && check(n, d, s, 11) && check(n, d, s, 13);

	if (n < 341550071728321)
		return check(n, d, s, 2) && check(n, d, s, 3) && check(n, d, s, 5) && check(n, d, s, 7) && check(n, d, s, 11) && check(n, d, s, 13) && check(n, d, s, 17);

	for (a = 2; a < bound; ++a)
	{
		if (!check(n, d, s, a))
			return 0;
	}

	return 1;
}