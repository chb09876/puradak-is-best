#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct node
{
	char			data;
	struct	node	*next;
}node;

typedef struct stack
{
	node	*end;
	int		cnt;
}stack;

void	init(stack *s);
void	empty(stack *s);
void	push(char X, stack *s);
void	pop(stack *s);
void	size(stack *s);
void	top(stack *s);

void	init(stack *s)
{
	s->end = NULL;
}

void	empty(stack *s)
{
	if (s->end == NULL)
		printf("1");
	else
		printf("0");
}

void	push(char X, stack *s)
{
	node	*tmp = (node *)malloc(sizeof(node));
	tmp->data = X;
	tmp->next = s->end;
	s->end = tmp;
	s->cnt++;
}

void	pop(stack *s)
{
	if (s->end == NULL)
		printf("-1");
	else
	{
		stack	*tmp = s->end;
		int		data = s->end->data;
		s->end = s->end->next;
		printf("%d", data);
		free(tmp);
		s->cnt--;
	}
}

void	size(stack *s)
{
	printf("%d\n", s->cnt);
}

void	top(stack *s)
{
	if (s->end == NULL)
		printf("-1");
	printf("0");
}

int main(void)
{
	int		N;
	int		cnt = 0;
	char	*str;
	stack	*s;
	scanf("%d", &N);
	for (int i = 0; i < N; i++)
	{
		scanf("%s", str);
		if (strcmp(str, "push") == 0)
		{
			char	X;
			scanf("%c", &X);
			push(X, s);
		}
		else if (strcmp(str, "pop") == 0)
			pop(s);
		else if (strcmp(str, "size") == 0)
			size(s);
		else if (strcmp(str, "empty") == 0)
			empty(s);
		else if (strcmp(str, "top") == 0)
			top(s);
	}
	return (0);
}