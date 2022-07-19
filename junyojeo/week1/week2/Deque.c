#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct node
{
	int				*data;
	struct	node	*;
	struct	node	*;
}node;

typedef struct deque
{
	deque	*first;
	deque	*last;
	int		cnt;
}deque;

void	init(deque *d)
{
	d->first = d->last = NULL;
}

void	push_front(int X, deque *d)
{
	node	*tmp = (deque *)malloc(sizeof(deque));
	tmp->data = X;
	tmp->next = rear;
	if (d->first == NULL)
		top = newnode;
	rear = newnode;
	cnt++;
}

void	push_back(deque *d)
{
	
}

void	pop_front(deque *d)
{
	if (d->first == NULL)
		printf("-1\n")
	else
	{
		printf("%d", d->last->data);
	}
}

void	pop_back(deque *d)
{
	if (d->first == NULL)
		printf("-1\n")
	else
	{
		printf("%d", d->last->data);
	}
}

void	size(deque *d)
{
	printf("%d\n", d->cnt);
}

void	empty(deque *d)
{
	if (d->first == NULL)
		printf("1");
	else
		printf("0");
}

void	front(deque *d)
{
	if (d->first == NULL)
		printf("-1\n");
	else
		printf(d->first->data);
}

void	back(deque *d)
{
	if (d->first == NULL)
		printf("-1\n");
	else
		printf(d->last->data);
}

int main(void)
{
	int		N;
	int		cnt = 0;
	char	str[10];
	deque	*d;
	
	scanf("%d", &N);
	for (int i = 0; i < N; ++i)
	{
		scanf("%s", &str);
		if (strcmp(str, "push") == 0)
		{
			int X;
			scanf("%d", &X);
			push(X, d);
		}
		else if (strcmp(str, "pop") == 0)
			pop();
		else if (strcmp(str, "size") == 0)
			size(cnt);
		else if (strcmp(str, "empty") == 0)
			empty();
		else if (strcmp(str, "front") == 0)
			front();
	}
	return (0);
}