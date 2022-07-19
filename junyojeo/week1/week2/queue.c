#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct node
{
	int				data;
	struct	node	*next;
}node;

typedef struct queue
{
	node	*first, *last;
	int		cnt;
}queue;

void	init(queue *q)
{
	q->first = q->last = NULL;
	q->cnt = 0;
}

int	empty(queue *q)
{
	if (q->first == NULL)
	{
		printf("-1");
		return (1);
	}
	return (0);
}

void	push(int data, queue *q)
{
	node	*tmp = (node *)malloc(sizeof(node));
	tmp->data = data;
	tmp->next = NULL;
	if (empty(q))
		q->first = q->last = tmp;
	else
	{
		q->last->next = tmp;
		q->last = tmp;
	}
	q->cnt++;
}

void	pop(queue *q)
{
	if (empty(q))
		printf("-1");
	else
	{
		node	*tmp = q->first;
		printf("%d", q->first->data);
		if (q->last == q->first)
			init(q);
		else
		{
			q->first = q->first->next;
			q->cnt--;
		}
		free(tmp);
	}
}

void	size(queue *q)
{
	printf("%d\n", q->cnt);
}

void	front(queue *q)
{
	if (empty(q))
		printf("-1");
	else
		printf(q->first->data);
}

void	back(queue *q)
{
	if (empty(q))
		printf("-1");
	else
		printf(q->last->data);
}

int main(void)
{
	int		N;
	char	str[10];
	queue	*q;

	init(q);
	scanf("%d", &N);
	for (int i = 0; i < N; ++i)
	{
		scanf("%s", &str);
		if (!strcmp(str, "push"))
		{
			int X;
			scanf("%d", &X);
			push(X, q);
		}
		else if (!strcmp(str, "pop"))
			pop(q);
		else if (!strcmp(str, "size"))
			size(q);
		else if (!strcmp(str, "empty"))
			empty(q);
		else if (!strcmp(str, "front"))
			front(q);
		else if (!strcmp(str, "back"))
			back(q);		
	}
	return (0);
}