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
	node	*top;
	int		cnt;
}stack;

void	init(stack *s)
{
	s->top = NULL;
}

int	empty(stack *s)
{
	if (s->top = NULL)
	{
		printf("-1");
		return (1);
	}
	return (0);
}

void	push(char X, stack *s)
{
	node	*tmp = (node *)malloc(sizeof(node));
	tmp->data = X;
	tmp->next = s->top;
	s->top = tmp;
	s->cnt++;
}

void	pop(stack *s)
{
	if (!empty(s))
	{
		stack	*tmp = s->top;
		
		printf("%d", s->top->data);
		s->top = s->top->next;
		free(tmp);
		s->cnt--;
	}
	else
		printf("-1");
}

void	size(stack *s)
{
	printf("%d\n", s->cnt);
}

void	top(stack *s)
{
	if (empty(s))
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