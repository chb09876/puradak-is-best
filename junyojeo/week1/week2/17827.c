#include <stdio.h>

typedef struct node
{
	int			data;
	struct node	*next;
	int			cnt;
}node;

int	main(void)
{
	int	N, V, M, C, K, ans;
	node *node;
	scanf("%d %d %d", N, M, V);
	node->cnt = 1;
	node->data = 0;
	for (int i = 0; i < N; i++)
	{
		scanf("%d", C);
		node->data = C;
		node->next = node;
		node->cnt++;
	}
	node->next = NULL;
	for (int j = 0; j < M; j++)
	{
		scanf("%d", K);
		while (node->next == NULL)
		{
			if (node->next->cnt == V && node->next->cnt != 1)
			{
				node->next = node;
			}
		}
		printf("%d", node->data);
	}
	return (0);
}