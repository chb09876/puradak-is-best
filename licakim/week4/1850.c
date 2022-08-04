#include<stdio.h>

int gcd(long long n1, long long n2)
{
    if(n2 ==0)
        return n1;
    else
        return gcd(n2, n1%n2);
}

int main()
{ 
    long long n1, n2;

    scanf("%lld %lld", &n1, &n2);
    int g= gcd(n1,n2);

    for(int i=0; i<g; i++)
    {
        printf("1");
    }
    printf("\n");
}
