#include <stdio.h>
#include <stdbool.h>
#include <math.h>

int get_digit(long long int n);
bool is_prime(long long int n);
bool is_palin(long long int n);

int main()
{
    int N;
    scanf("%d", &N);
    while (!(is_palin(N) && is_prime(N)))
        ++N;
    printf("%d", N);
}

int get_digit(long long int n)
{
    int digit = 0;
    while (n)
    {
        n /= 10;
        ++digit;
    }
    return digit;
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

bool is_palin(long long int n)
{
    int digit = get_digit(n);
    int repeat = digit / 2;
    for (int i = 0; i < repeat; ++i)
    {
        if (n / (long long int)pow(10, digit - 1) != n % 10)
            return false;
        n %= (long long int)pow(10, digit - 1);
        n /= 10;
        digit -= 2;
    }
    return true;
}