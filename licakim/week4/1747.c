#include<stdio.h>

int is_prime(int num)
{
    for(int i = 2; i*i <= num; i++)
    {
        if(num % i == 0)
            return 0;
    }
    return 1;
}

int check(int num)
{
    int arr[7];
    int i = 0;
    while(num)
    {
        arr[i++]= num%10;
        num = num /10;
    }
	i--;
    for(int k=0 ; k <=i/2; k++)
    {
        if(arr[k] != arr[i-k])
			return 0;
    }
    return 1;
}

int main()
{
    int a[1003002]={0,};
    for(int i =2; i <1003002; i++)
    {
        if(is_prime(i)&&check(i))
        {
            a[i] = 1;
        }
    }

    int n;
    scanf("%d", &n);

    while(a[n]==0)
    {
        n++;
    }
    printf("%d\n",n);
}
