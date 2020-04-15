#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MAX_VAL 2095000
int m;
int num;
int primes[MAX_VAL];

typedef enum
{
    false,
    true
} bool;



int is_prime(int n)
{
    if (n <= 3)
        return 1;
    if (n % 2 == 0 || n % 3 == 0)
        return 0;

    for (m = 5; m < (int)sqrt(n) + 1; m = m + 6)
    {
        if (n % m == 0 || n % (m + 2) == 0)
            return 0;
    }
    return 1;
}

void SieveOfAtkin(int lmt)
{
    primes[2]=1;
    primes[3]=1;
    primes[4]=0;
    primes[5]=1;
    primes[1]=0;
    bool sieve[lmt];
    for (int i = 0; i < lmt; i++)
        sieve[i] = false;
    for (int a = 1; a * a < lmt; a++)
    {
        for (int b = 1; b * b < lmt; b++)
        {
            // Main part of Sieve of Atkin
            int n = (4 * a* a) + (b * b);
            if (n <= lmt && (n % 12 == 1 || n % 12 == 5))
                sieve[n] ^= true;
            n = (3 * a * a) + (b * b);
            if (n <= lmt && n % 12 == 7)
                sieve[n] ^= true;
            n = (3 * a * a) - (b * b);
            if (a > b && n <= lmt && n % 12 == 11)
                sieve[n] ^= true;
        }
    }
    for (int r = 5; r * r < lmt; r++)
    {
        if (sieve[r])
        {
            for (int i = r * r; i < lmt; i += r * r)
                sieve[i] = false;
        }
    }
    for (int x = 5; x < lmt; x++)
        primes[x]=sieve[x];
}

int main(int argc, char *argv[])
{
    FILE *file = fopen(argv[1], "r");
    char buf[1000];
    SieveOfAtkin(MAX_VAL);
    while (fgets(buf, 1000, file) != NULL)
    {

        num = atoi(buf);
        if(num<=MAX_VAL)
            printf("%d\n", primes[num]);
        else
            printf("%d\n", is_prime(num));

    }
    fclose(file);
    return 0;
}

