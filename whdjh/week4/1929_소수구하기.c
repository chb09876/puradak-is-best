#include <stdio.h>

int main()
{
    int M, N;
    int i, j, arr[1000001] = {0, };
    
    arr[0] = 1, arr[1] = 1;
    for(j = 2; j < 1000001 / j; j++)
    {
        if(arr[j] == 1) 
            continue;
        for(i = j * j; i < 1000001; i += j)
        {
            if(i % j == 0)
                arr[i] = 1;
        }
    }
    scanf("%d %d", &M, &N);
    
    for(i = M; i <= N; i++)
    {
        if(arr[i] == 0)
            printf("%d\n", i);
    }
    return 0;
}