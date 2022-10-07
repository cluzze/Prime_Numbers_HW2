#include "prime_tests.h"
#include "sieve.h"

#include <stdio.h>
#include <assert.h>
#include <time.h>

#define SIZE 10
#define BIL 1000000

long long input[SIZE]  = {1,  6, 100,  500, 1000,  3000,  4000,  15000,  20000};
long long expect[SIZE] = {2, 13, 541, 3571, 7919, 27449, 37813, 163841, 224737};

int naive_is_prime(long long n)
{
	if ((n == 2) || (n == 3)) return 1;

	if ((n < 2) || ((n % 2) == 0) || ((n % 3) == 0)) return 0;
	
	for (long long j = 5; j * j <= n; j += 6)
		if (((n % j) == 0) || ((n % (j + 2)) == 0))
			return 0;
	
	return 1;
}

int main()
{
	clock_t start, end;
	double cpu_time_used;
	long long n = 0, i = 0;
	//long long nprime = 0;
	struct sieve_t sieve;
	//scanf("%lld", &n);
	
	n = 10000;

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

		/*start = clock();
		for (i = 6; i < sieve.n; i += 6)
		{
			if (rabin_miller(i - 1) != is_prime(&sieve, i - 1))
			{
				printf("Failed on %lld, rabin_miller: %d, is_prime: %d\n", i - 1, rabin_miller(i - 1), is_prime(&sieve, i - 1));
			}


			if (rabin_miller(i + 1) != is_prime(&sieve, i + 1))
			{
				printf("Failed on %lld, rabin_miller: %d, is_prime: %d\n", i + 1, rabin_miller(i + 1), is_prime(&sieve, i + 1));
			}
		}
		end = clock();
		cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
		printf("testing through sieve: %g sec\n", cpu_time_used);
*/
	start = clock();
	for (i = BIL + 1; i < 1000 * BIL; i += BIL)
	{
		if (rabin_miller(i) != naive_is_prime(i))
		{
			printf("Failed on %lld, rabin_miller: %d, is_prime: %d\n", i, rabin_miller(i), naive_is_prime(i));
		}
	}
	end = clock();
	cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
	printf("testing through naive_is_prime: %g sec\n", cpu_time_used);

	while (!rabin_miller(i))
		i += 2;

	printf("%lld\n", i);
	printf("%d", naive_is_prime(1000000007));

	//printf("%d\n", rabin_miller(n));

	return 0;
}