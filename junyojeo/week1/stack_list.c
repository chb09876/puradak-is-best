#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct stack
{
	int				*data;
	struct	stack	*next;
}stack;

stack	*stack_top;

void	push(int cnt, int *data)
{
	stack	*newnode = (stack *)malloc(sizeof(stack));
	newnode->data = data;
	newnode->next = stack_top;
	stack_top = newnode;
	cnt++;
}

void	pop()
{
	if (empty())
		printf("-1");
	else
	{
		printf("%d", stack_top->data);
		free(stack_top);
	}
}

void	size(int cnt)
{
	printf("%d\n", cnt);
}

void	top()
{
	if (empty())
		printf("-1");
	printf("0");
}

int	empty()
{
	if (stack_top == NULL)
	{
		printf("-1");
		return (1);
	}
	return (0);
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
		else if (strcmp(str, "top") == 0)
			top();
	}
	return (0);
}