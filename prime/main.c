#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MAX_VAL 99999
unsigned long int m;
unsigned long int num;
unsigned long int primes[MAX_VAL];

typedef enum
{
    false,
    true
} bool;



unsigned long int is_prime(unsigned long int n)
{
    if (n <= 3)
        return 1;
    if (n % 2 == 0 || n % 3 == 0)
        return 0;

    for (m = 5; m < (unsigned long int)sqrt(n) + 1; m = m + 6)
    {
        if (n % m == 0 || n % (m + 2) == 0)
            return 0;
    }
    return 1;
}

void SieveOfAtkin(bool *sieve ,unsigned long int lmt)
{


    for (unsigned long int i = 0; i < lmt; i++)
        sieve[i] = false;
    for (unsigned long int a = 1; a * a < lmt; a++)
    {
        for (unsigned long int b = 1; b * b < lmt; b++)
        {
            // Main part of Sieve of Atkin
            unsigned long int n = (4 * a* a) + (b * b);
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
    for (unsigned long int r = 5; r * r < lmt; r++)
    {
        if (sieve[r])
        {
            for (unsigned long int i = r * r; i < lmt; i += r * r)
                sieve[i] = false;
        }
    }

    sieve[3]=sieve[5]=sieve[2]=1;
    sieve[4]=sieve[1]=0;

}

unsigned long int main(unsigned long int argc, char *argv[])
{
    FILE *file =
    fopen(argv[1], "r");
    char buf[99999];
    bool sieve[MAX_VAL];
    SieveOfAtkin(sieve,MAX_VAL);
    while (fgets(buf, 99999, file) != NULL)
    {

        num = atoi(buf);
        if(num<=MAX_VAL)
            printf("%d\n", sieve[num]);
        else
            printf("%d\n", is_prime(num));

    }
    fclose(file);
    return 0;
}
