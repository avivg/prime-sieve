#include <stdio.h>
#include <stdlib.h>
#include <memory.h>

int max;
char *primes;
int next_prime;

void find_next_prime()
{
    next_prime++;
    while (next_prime <= max && (!primes[next_prime]))
    {
        next_prime++;
    }
}

void filter_nums()
{
    long long lnp = next_prime;
    long long idx = lnp * lnp;
    while (idx <= max)
    {
        primes[idx] = 0;
        idx += lnp;
    }
}

long long sum_primes()
{
    long long sum = 0;
    while(1)
    {
        find_next_prime();
        if (next_prime > max) {
            return sum;
        }
        sum += next_prime;
        filter_nums();
    }
}

int main()
{
    max = 2000000;
    next_prime = 1;
    primes = (char*)malloc((max + 1) * sizeof(char));
    if (!primes)
        return -1;
    memset(primes, 1, max + 1);
    printf("%llu\n", sum_primes());
    return 0;
}