#include<stdio.h>

void ft_print_res(int result[], int m)
{
    for(int i = 0; i<m; i++)
    {
        printf("%d ",result[i]);
    }
    printf("\n");
}


void array(int i, int m, int n, int arr[],int result[])
{
    int j;

    if(i == 7)
    {
        ft_print_res(result, m);
        printf("\n");
    }
    else
    {
        j = 1;
        while(j<=n)
        {
            if(arr[j]==0)
            {
                result[i] = j;
                arr[j] = 1;
                array(i+1,m,n,arr,result);
                arr[j] = 0;
            }
            j++;
        }
    }
}

int main()
{
    int n, m;
    int arr[1000] ={0,};
    int res[1000];

    scanf("%d %d", &n, &m);
    array(0,m,n,arr,res);
}
