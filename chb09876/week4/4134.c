#include <stdio.h>
#include <stdbool.h>

bool is_prime(long long int n);
long long int get_next_prime(long long int n);

int main()
{
    int T;
    scanf("%d", &T);
    while (T--)
    {
        long long int n;
        scanf("%lld", &n);
        printf("%lld\n", get_next_prime(n));
    }
}

bool is_prime(long long int n)
{
    if (n == 0 || n == 1)
        return false;
    for (long long int i = 2; i * i <= n; ++i)
    {
        if (n % i == 0)
            return false;
    }
    return true;
}

long long int get_next_prime(long long int n)
{
    while (!is_prime(n))
        ++n;
    return n;
}