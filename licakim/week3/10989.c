#include<stdio.h>

int main()
{
    int count_num[10001]={0};
    int n,num;

    scanf("%d", &n);

    while(n > 0)
    {
        scanf("%d", &num);
        count_num[num]++;
        n--;
    }

    for(int i = 0; i<n; i++)
    {
        for(int j = 0; j<count_num[i]; j++)
        {
            printf("%d",i);

        }
    }
}
