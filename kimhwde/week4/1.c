//에라토스테네스의 체
#include <stdio.h>
int main(void){
    int m,n,arr[1000001] = {0,};// 0으로 초기화
    arr[1] = 1;//소수 아니라서 일단 1로 초기화
    
    scanf("%d %d", &m, &n);
    
    for(int i = 2; i <= n; i++){//이중 구문의 표상? 이미지? 추상화?   2부터 입력받은 n까지의 각 수의 배수들을 지워나간다 0넣으면 삭제로 간주
        for(int j = 2; i * j <= n; j++){
            arr[i*j] = 1;//해당 수의 배수들은 소수가 아니므로 1로 세팅
        }
    }
    
    for(int i = m; i <= n; i++)
    {
        if(arr[i] == 0)//배열에서 값이 0인 인덱스들은 소수임!!!
            printf("%d\n",i);
    }
    
    return 0;
}