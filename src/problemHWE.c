#include "prime_tests.h"
#include "sieve.h"

#include <stdio.h>
#include <assert.h>

#define SIZE 10

long long input[SIZE]  = {1,  6, 100,  500, 1000,  3000,  4000,  15000,  20000};
long long expect[SIZE] = {2, 13, 541, 3571, 7919, 27449, 37813, 163841, 224737};

int main()
{
	int n = 0, i = 0;
	//long long nprime = 0;
	struct sieve_t sieve;
	scanf("%d", &n);
	
	init_sieve(&sieve, n);
	fill_sieve(&sieve);

/*	for (i = 0; i < SIZE; ++i)
	{
		nprime = nth_prime(&sieve, input[i]);
		if (nprime != expect[i])
		{
			printf("Failed %d: expected: %lld, got: %lld\n", i, expect[i], nprime);
		}
	}*/

	for (i = 0; i < sieve.n; ++i)
	{
		if (rabin_miller(i) != is_prime(&sieve, i))
		{
			printf("Failed on %d, rabin_miller: %d, is_prime: %d\n", i, rabin_miller(i), is_prime(&sieve, i));
		}
	}

	//printf("%d\n", rabin_miller(n));

	return 0;
}