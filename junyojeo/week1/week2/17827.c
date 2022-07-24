#include <stdio.h>

int	main(void)
{
	int C[200001];
	int	N, V, M;
	scanf("%d %d %d", N, M, V);
	for (int i = 0; i < N; i++)
		scanf("%d", C[i]);
	for (int j = 0; j < M; j++)
	{
		int K;
		scanf("%d", K);
		if (K < V - 1)
			printf("%d", C[K]);
		else
			printf("%d", C[(K - V - 1) % (N - V - 1) + V - 1]);
	}
	return (0);
}