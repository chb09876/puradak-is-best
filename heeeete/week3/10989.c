#include <stdio.h>

int main()
{
    int N;
    scanf("%d", &N);
    int arr[100001] = {0,};
    int count;
    for (int i = 0 ; i < N ; i++)
    {
        scanf("%d", &count);
        arr[count]++;
    }
    int i = 1;
    while(i <= 100000)
    {
        if(arr[i] != 0)
        {
            printf("%d\n", i);
            arr[i]--;
        }
        else
            i++;
    }
}