#include <stdio.h>
#include <stdbool.h>
#include <string.h>

#define SIZE 1000000

void make_sieve(bool *sieve, long long int len);
bool SIEVE[SIZE];

int main()
{
    make_sieve(SIEVE, SIZE);
    int T;
    scanf("%d", &T);
    while (T--)
    {
        int N;
        scanf("%d", &N);
        int count = 0;
        for (int i = 2; i <= N / 2; ++i)
        {
            if (SIEVE[i - 1] && SIEVE[N - i - 1])
                ++count;
        }
        printf("%d\n", count);
    }
}

void make_sieve(bool *sieve, long long int len)
{
    int count = 0;
    memset(sieve, true, len);
    sieve[0] = false;
    for (long long int i = 1; i < len; ++i)
    {
        if (sieve[i] == true)
        {
            for (long long int j = (i + 1) * (i + 1) - 1; j < len; j += (i + 1))
            {
                if (sieve[j] == true)
                {
                    sieve[j] = false;
                }
            }
            if ((i + 1) * (i + 1) > len)
                break;
        }
    }
}