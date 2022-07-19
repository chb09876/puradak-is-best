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
	node	*last;
	int		cnt;
}stack;

void	init(stack *s)
{
	s->last = NULL;
}

int	empty(stack *s)
{
	int	emp;
	if (s->last == NULL)
		emp = 1;
	else
		emp = 0;
	printf("%d", emp);
	return (emp);
}

void	push(char X, stack *s)
{
	node	*tmp = (node *)malloc(sizeof(node));
	tmp->data = X;
	tmp->next = s->last;
	s->last = tmp;
	s->cnt++;
}

void	pop(stack *s)
{
	if (!empty(s))
	{
		stack	*tmp = s->last;
		int		data = s->last->data;
		s->last = s->last->next;
		printf("%d", data);
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