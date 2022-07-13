#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct queue
{
	int				*data;
	struct	queue	*next;
}queue;

queue	*top;
queue	*rear;

void	init()
{
	top = rear = NULL;
}

void	add_rear(Deque *q)
{
	
}

void	push(int cnt, int *data)
{
	queue	*newnode = (queue *)malloc(sizeof(queue));
	newnode->data = data;
	newnode->next = rear;
	if (empty(top))
		top = newnode;
	rear = newnode;
	cnt++;
}

void	pop()
{
	if (empty())
		printf("-1");
	else
	{
		queue *tmp;
		tmp = top;
		printf("%d", top->data);
		top = top->next;
		free(tmp->data);
	}
}

void	size(int cnt)
{
	printf("%d\n", cnt);
}

int	empty()
{
	if ( == NULL)
	{
		printf("-1");
		return (1);
	}
	return (0);
}

void	front()
{
	if (empty())
		printf("-1");
	else
		printf(top->data);
}

void	back()
{
	if (empty())
		printf("-1");
	else
		printf(rear->data);
}


int main(void)
{
	int		N;
	int		cnt = 0;
	char	str[10];
	scanf("%d", &N);
	for (int i = 0; i < N; ++i)
	{
		scanf("%s", &str);
		if (strcmp(str, "push") == 0)
		{
			int data;
			scanf("%d", &data);
			push(cnt, &data);
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