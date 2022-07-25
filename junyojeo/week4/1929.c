#include <stdio.h>//에라토스테네스의 체
#define SWAP(x, y, t) ( (t) = (x), (x) = (y), (y) = (t) )

int a[1000001];//배열 전역변수로 선언해야하는 이유, 0으로 자동 초기화되는 이유

int main(void)
{
	int M, N;
	scanf("%d %d", &M, &N);
	for (int i = 2; i <= N; i++)
	{
		if (a[i] == 0)
		{
			for (int j = i + i; j <= N; j += i)
				a[j] = 1;
		}
		if(i >= M && a[i] == 0)
			printf("%d\n", i);
	}
	return (0);
}