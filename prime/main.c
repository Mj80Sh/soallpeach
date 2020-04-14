#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int m;
int num;
int primes[99992];

typedef enum {
    false,
    true
} bool;

int sum_digit(long int n)
{
    int sum=0,m;
    while(n>0)
    {
        m=n%10;
        sum=sum+m;
        n=n/10;
    }

    return sum;
}


int is_prime(int n)
{
    if ((n%10)%2==0 || sum_digit(n)%3==0)
        return 0;
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
    SieveOfAtkin(99992);
    while (fgets(buf, 1000, file) != NULL)
    {

        num = atoi(buf);
        if(num<=99992)
            printf("%d\n", primes[num]);
        else
            printf("%d\n", is_prime(num));

    }
    fclose(file);
    return 0;
}

