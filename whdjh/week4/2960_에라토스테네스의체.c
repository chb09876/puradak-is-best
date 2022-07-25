#include <stdio.h>

int cnt = 0;
int isprime[1001];

int is_prime(int n, int k)
{
    for(int i = 2; i <= n; i++)
    {
        if(isprime[i] == 0)
        {
            cnt++;
            if(cnt == k)
                return i;
            for(int j = i * i; j <= n; j += i)
            {
                if(isprime[j] == 0)
                {
                    isprime[j] = 1;
                    cnt++;
                    if(cnt == k)
                    {
                        return j;
                    }
                }
            }
        } 
    }
}

int main()
{
    int n, k;
    scanf("%d %d", &n, &k);
    printf("%d\n", is_prime(n, k));
    return 0;
}