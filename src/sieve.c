#include "sieve.h"
#include "myassert.h"

#include <math.h>
#include <stdlib.h>
#include <limits.h>

int is_bit_zero(unsigned char *s, long long i)
{
	unsigned char bit;

	MYASSERT(s)

	bit = ((s[i / CHAR_BIT] >> (i % CHAR_BIT)) & 1) == 0;
	return bit;
}

void set_bit(unsigned char *s, long long i)
{
	MYASSERT(s)

	s[i / CHAR_BIT] |= (1 << (i % CHAR_BIT));
}

void fill_sieve(struct sieve_t *sv)
{
	long long i = 0, j = 0;

	MYASSERT(sv)
	MYASSERT(sv->mod1)
	MYASSERT(sv->mod5)

	set_bit(sv->mod1, 0);

	for (i = 2; i < sv->n * CHAR_BIT * 6; ++i)
	{
		if (is_prime(sv, i))
		{
			for (j = i * i; j < sv->n * CHAR_BIT * 6; j += i)
			{
				if (j % 6 == 1)
					set_bit(sv->mod1, j / 6);
				if (j % 6 == 5)
					set_bit(sv->mod5, j / 6);
			}
		}
	}
}

void init_sieve(struct sieve_t *sieve, int n)
{
	MYASSERT(sieve)
	MYASSERT(n > 0)

	sieve->n = sieve_bound(n);

	sieve->mod1 = (unsigned char*)calloc(sieve->n, sizeof(char));
	sieve->mod5 = (unsigned char*)calloc(sieve->n, sizeof(char));

	fill_sieve(sieve);
}

void destroy_sieve(struct sieve_t *sieve)
{
	MYASSERT(sieve)

	free(sieve->mod1);
	free(sieve->mod5);
}

int sieve_bound(int num)
{
	double dnum, dres;

	if (num <= 20)
		return 100;

	dnum = num;
	dres = dnum * (log(dnum) + log(log(dnum)));

	return (int)round(dres);
}

int is_prime(struct sieve_t *sv, unsigned n)
{
	MYASSERT(sv)

	if (n == 2 || n == 3)
		return 1;

	if ((n % 6 != 1) && (n % 6 != 5))
		return 0;


	if (n % 6 == 1)
		return is_bit_zero(sv->mod1, n / 6);

	return is_bit_zero(sv->mod5, n / 6);
}

int nth_prime(struct sieve_t *sv, int n)
{
	int cur = 0;
	int i   = 0;

	MYASSERT(sv)

	while (i < sv->n)
	{
		if (is_prime(sv, i))
		{
			cur++;
		}

		if (cur == n)
			return i;

		i++;
	}

	return -1;
}