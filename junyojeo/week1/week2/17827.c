#include <stdio.h>
#include <stdlib.h>

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
	for (int i = 0; i < N; i++)
	{
		scanf("%d", C);
		node->data = C;
		node->next = node;
		node->cnt++;
	}
	node->next = NULL;
	int	j = 0;
	while (j < M)
	{
		scanf("%d", K);
		while (node->next == NULL)
		{
			if (node->next->cnt == V)
			{
				node->next = node;
			}
		}
		printf("%d", node->data);
		j++;
	}
	return (0);
}