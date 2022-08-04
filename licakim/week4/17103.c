#include<stdio.h>

int is_prime(int num);
void partition(int num, int *a);

void partition(int num, int *a)
{
    int count = 0;

    for(int i = 2; i <= num/2 ; i++)
    {
        if(a[i]&&a[num-i])
            count++;
    }
    printf("%d\n", count);
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
    int arr[1000001];

    for(int i =1; i <1000001; i++)
    {
        arr[i]=is_prime(i);
    }

    int n,num;

    scanf("%d", &n);

    for(int i=0; i<n; i++)
    {
        scanf("%d",&num);
        partition(num,arr);
    }

}