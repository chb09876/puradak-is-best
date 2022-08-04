#include<stdio.h>

int cnt_p(int*prime, int c);

void find(int n, int k, int *prime, int *arr,int cnt)
{
   int p = cnt_p(prime,cnt);
   if(p > n)
        return;
   cnt++;
   for(int i=1; i*p <=n; i++)
   {
        if(arr[i*p]!=0)
        {
            arr[i*p]=0;
            k--;
        }
        if(k == 0)
        {
            printf("%d\n",i*p);
            return;
        }
   }
   find(n,k,prime,arr,cnt);
}

int cnt_p(int*prime, int c)
{
    int count =0;

    for(int i = 2; i<1001;i++)
    {
        if(prime[i]==1)
            count++;
        if(count == c)
            return i;   
    }
}

int is_prime(int num)
{
    for(int i = 2; i*i <= num; i++)
    {
        if(num % i == 0)
            return 0;
    }

    return 1;
}

int main()
{
    int prime[1001];
    int arr[1001];

    for(int i =2; i <1001; i++)
    {
        prime[i]=is_prime(i);
    }

    for(int i=2; i<1001; i++)
    {
        arr[i]= i;
    }

    int n,k;
    int cnt =1;
    scanf("%d %d", &n, &k);
    find(n,k,prime,arr,cnt);
}
