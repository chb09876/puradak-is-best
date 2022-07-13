#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct node
{
	int				data;
	struct	node	*next;
}node;

node	*first;
node	*last;
int		cnt = 0;

int	empty(int cnt)
{
	if (cnt == 0)
	{
		printf("-1");
		return (1);
	}
	return (0);
}

void	push(int data)
{
	node	*newnode = (node *)malloc(sizeof(node));
	newnode->data = data;
	newnode->next = NULL;
	if (empty(cnt))
		first = newnode;
	else
		last->next = newnode;//
	last = newnode;
	cnt++;
}

void	pop()
{
	if (empty(cnt))
		printf("-1");
	else
	{
		node	*tmp;
		tmp = first;
		first = tmp->next;
		printf("%d", tmp->data);
		free(tmp);
		cnt--;
	}
}

void	size(int cnt)
{
	printf("%d\n", cnt);
}

void	front()
{
	if (empty(cnt))
		printf("-1");
	else
		printf(first->data);
}

void	back()
{
	if (empty(cnt))
		printf("-1");
	else
		printf(last->data);
}

int main(void)
{
	int		N;
	char	str[10];

	scanf("%d", &N);
	for (int i = 0; i < N; ++i)
	{
		scanf("%s", &str);
		if (strcmp(str, "push") == 0)
		{
			int data;
			scanf("%d", &data);
			push(data);
		}
		else if (strcmp(str, "pop") == 0)
			pop();
		else if (strcmp(str, "size") == 0)
			size(cnt);
		else if (strcmp(str, "empty") == 0)
			empty(cnt);
		else if (strcmp(str, "front") == 0)
			front();
	}
	return (0);
}