#include <stdio.h>

long long int GCD(long long int a, long long int b)
{
    if(b == 0)
        return a;
    else
        return GCD(b, a % b);
}

int main()
{
    long long int a, b;
    scanf("%lld %lld", &a, &b);
    for(int i = 0; i < GCD(a, b); i++)
        printf("1");
    printf("\n");
    return 0;
}