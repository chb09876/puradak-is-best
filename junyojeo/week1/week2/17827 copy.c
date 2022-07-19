#include <stdlib.h>
#include <stdio.h>

typedef struct node
{
	int			data;
	struct node	*next;
	int			cnt;
}node;

int	main(void)
{
	node *head = (node *)malloc(sizeof(node));
	node *n = (node *)malloc(sizeof(node));
	node *ans = (node *)malloc(sizeof(node));
	node *tmp = (node *)malloc(sizeof(node));
	head->next = n;
	head->cnt = 0;
	tmp->next = n;
	int	N, M, V;
	scanf("%d %d %d", N, M, V);
	for (int i = 0; i < N; i++)
	{
		int C;
		scanf(" %d", C);
		head->cnt++;
		n->cnt = head->cnt; 
		n->data = C;
		n = n->next;
	}
	while (n->next = NULL)
	{
		if (head->cnt == V)
		{
			ans = head;
			break;
		}
		head->next = head;
	}
	for (int j = 0; j < M; j++)
	{
		int K;
		scanf("%d", K);
		for (int i = 0; i < ((K - V - 1) % (N - V - 1)) + V - 1; i++)
		{
			if (tmp->next->cnt == V && tmp->next->cnt != 1)
			{
				tmp= tmp->next;
			}
			tmp = tmp->next;
		}
		printf("%d", tmp->data);
	}
	return (0);
}