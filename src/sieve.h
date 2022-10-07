#ifndef _SIEVE_
#define _SIEVE_

struct sieve_t
{
	int n;
	unsigned char *mod1;
	unsigned char *mod5;
};

int is_bit_zero(unsigned char *s, long long i);

void set_bit(unsigned char *s, long long i);

int sieve_bound(int num);

void init_sieve(struct sieve_t *sieve, int n);

void destroy_sieve(struct sieve_t *sieve);

int is_prime(struct sieve_t *sv, unsigned n);

void fill_sieve(struct sieve_t *sv);

int nth_prime(struct sieve_t *sv, int n);

#endif