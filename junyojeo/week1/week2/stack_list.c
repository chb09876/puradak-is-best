#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct stack
{
	char			data;
	struct	stack	*next;
}stack;

stack	*stack_top;

int	empty()
{
	if (!stack_top)
	{
		printf("-1");
		return (1);
	}
	return (0);
}

void	push(char data, int cnt)
{
	stack	*newnode = (stack *)malloc(sizeof(stack));
	newnode->data = data;
	newnode->next = stack_top;
	stack_top = newnode;
	cnt++;
}

void	pop(int cnt)
{
	if (!empty())
	{
		stack	*tmp = stack_top;
		char	data = tmp->data;
		stack_top = tmp->next;
		printf("%d", stack_top->data);
		free(stack_top);
		cnt--;
	}
	else
		printf("-1");
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

int main(void)
{
	int		N;
	int		cnt = 0;
	char	*str;
	scanf("%d", &N);
	for (int i = 0; i < N; i++)
	{
		scanf("%s", str);
		if (strcmp(str, "push") == 0)
		{
			char	data;
			scanf("%c", &data);
			push(cnt, data);
		}
		else if (strcmp(str, "pop") == 0)
			pop(cnt);
		else if (strcmp(str, "size") == 0)
			size(cnt);
		else if (strcmp(str, "empty") == 0)
			empty();
		else if (strcmp(str, "top") == 0)
			top();
	}
	return (0);
}