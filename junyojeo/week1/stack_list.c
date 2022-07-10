#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int	empty()
{
	if (top == NULL)
	{
		printf("-1");
		return (1);
	}
	return (0);
}

typedef struct
{
	int		*data;
	stack	*next;
}stack;

stack	*stack_top;

void	push(data)
{
	stack	*newnode = (stack *)malloc(sizeof(stack));
	newnode->data = data;
	newnode->next = top;
	stack_top = newnode;
}

void	pop()
{
	if (empty)
		printf("-1");
	else
	{
		printf("%d", stack_top->data);
		free(top);
	}
}

void	size(void)
{
	printf("%d\n", top + 1);
}

int	empty()
{
	if (top == NULL)
	{
		printf("-1");
		return (1);
	}
	return (0);
}

void	top()
{
	if (empty)
		printf("-1");
	printf("0");
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
			push();
		}
		else if (strcmp(str, "pop") == 0)
			pop();
		else if (strcmp(str, "size") == 0)
			size();
		else if (strcmp(str, "empty") == 0)
			empty();
		else if (strcmp(str, "top") == 0)
			top();
	}
	return (0);
}