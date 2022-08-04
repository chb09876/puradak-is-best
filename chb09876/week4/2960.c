#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#define SIZE 1000

void make_sieve(bool *sieve, long long int size, int K);

bool sieve[SIZE];

int main()
{
    int N, K;
    scanf("%d %d", &N, &K);

    make_sieve(sieve, N, K);
}

void make_sieve(bool *sieve, long long int len, int K)
{
    int count = 0;
    memset(sieve, true, len);
    sieve[0] = false;
    for (long long int i = 1; i < len; ++i)
    {
        if (sieve[i] == true)
        {
            if (++count == K)
            {
                printf("%d", i + 1);
                return;
            }
            for (long long int j = (i + 1) * (i + 1) - 1; j < len; j += (i + 1))
            {
                if (sieve[j] == true)
                {
                    sieve[j] = false;
                    if (++count == K)
                    {
                        printf("%d", j + 1);
                        return;
                    }
                }
            }
            // if ((i + 1) * (i + 1) > len)
            //     break;
        }
    }
}