#include <stdio.h>

int main()
{
    int num, n;
    int cnt[10001] = { 0 }; //카운팅정렬: 크기를 갯수로 세어보자라는 마인드
    
    scanf("%d", &n);
    for(int i = 0; i < n; i++)
    {
        int temp;
        scanf("%d", &temp);
        cnt[temp]++;    //개수세서 정렬
    }
    for(int i = 0; i < 10001; i++)
    {
        for(int j = 0; j < cnt[i]; j++)
            printf("%d\n", i);
    }
    return 0;
}