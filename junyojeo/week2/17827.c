#include <stdlib.h>
#include <stdio.h>

typedef struct node
{
	int			data;
	struct node	*next;
	int			cnt;
}node;

void	add_node(node *n, int X)
{
	node *tmp = (node *)malloc(sizeof(node));
	tmp->next = n->next;
	tmp->data = X;
	tmp->cnt = n->cnt++;
	n->next = tmp;
	n->cnt++;
}

void	remove_head(node *n)//생각보다 간단한거 기억하기
{
	node *tmp = n->next;
	n->next = tmp->next;
	free(tmp);
}

int	main(void)
{
	node *n = (node *)malloc(sizeof(node));
	n->next = NULL;
	n->cnt = 0;
	int	N, V, M, C, K, ans;
	scanf("%d %d %d", N, M, V);
	for (int i = 0; i < N; i++)
	{
		scanf("%d", C);
		add_node(n, C);
	}
	n->cnt = 0;
	remove_head(n);
	node *cur = n->next;
	while (cur->next != V)
	{
		if (cur->next == V)
			
	}
	for (int j = 0; j < M; j++)
	{//N - (V-1)
		scanf("%d", K);
		while (K - V + 1 )
		{
			if (cur->next->cnt == V && cur->next->cnt != 1)
			{
				cur->next = cur;
			}
		}
		printf("%d", cur->data);
	}
	return (0);
}