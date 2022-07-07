#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct	node
{
	int			data;
	struct node	*next;
}node;

typedef struct	Que//?
{
	node	*front;
	node	*back;
	int		cnt;
}que;

void	init_q(que *q)
{
	q->front = NULL;
	q->back = NULL;
	q->cnt = 0;
}

void	push(que *q, int X)
{
	node *idx = (node *)malloc(sizeof(node));
	idx->data = X;
	idx->next = NULL;

	if (empty)
		q->front = idx;
	else
		q->back = idx;
	q->back = idx;
	q->cnt++;
}

int	pop(que *q)
{
	int tmp;
	
	node *idx;
	if (empty)
		return (0);
	idx = q->front;
	q->front = idx->next;
	tmp = idx->data;
	free(idx);
	q->cnt--;
	return tmp;
}

void	size(que *q)
{
	return (q->cnt);
}

void	empty(que *q)
{
	if (q->cnt == 0)
		return (0);
}

void	front(que *q)
{
	if (empty)
	{

	}
	else
		reut

}

int	main(void)
{
	int i;
	que q;

	int N;
	char str[10];
	scanf("%d", &N);
	
	init_q(q);
	for (i = 1; i <= 5; ++i)
		push(&q, i);
	while (!isempty(&q))
		printf("%d ", pop(&q));
	printf("\n");
	return (0);
}
