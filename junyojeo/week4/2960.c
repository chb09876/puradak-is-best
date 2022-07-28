#include <stdio.h>

int main(void)
{
	int N, K;
	scanf ("%d %d", &N, &K);
	int arr[N], P;
	for (int i = 2; i < N; i++)
		arr[i] = 1;
	for (int i = 2; i < N; i++)
	{
		if (arr[i] == 1)
		{
			P = i;
			for (int j = 2; P < N; P *= j)
			{
				arr[P] = 0;
				if (K == 0)
					break;
				K--;
			}
			if (K == 0)
			{
				printf("%d", P);
				return (0);
			}
		}
	}
	printf("K가 N을 초과하는 소수가 된 것 같다.");
	return (0);
}