#include <iostream>
#include <algorithm>


int prime(int n,int k) {
	int visited[1001] = { 0 };//0으로 초기화 하고..쓰레기 값?
	int cnt = 0;
	for (int i = 2; i <= n; i++) {
		visited[i] = i; //값을 초기화
	}
	for (int i = 2; i <= n; i++) //이중for문을 통해서 2부터 해당수의 배수들을 주어진 범위내에서 삭제 
	{
		for (int j = i; j <= n; j += i) 
        {
			if (visited[j] == 0) 
                continue; //이미 삭제한 숫자는 0이되어 반복문이 돌지 않게함
            cnt++;//지운 횟수 증가
			if (cnt == k) {//
				return visited[j];//마지막으로 지우는 값을 반환하면서 함수종료
			}
			visited[j] = 0;//해당 j는 지움,0을 넣으면 지운것으로 간주
		}
		
	}

}


int main() {
	int n, k;
	scanf("%d %d", &n, &k);
	printf("%d",prime(n, k));//마지막으로 지운값 출력
}
