#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define	STACK_SIZE 1

int	idx = -1;

void	push(int k, int *stack)
{
	int stack_size = STACK_SIZE;//define값 변경이 안돼서 넣어봄
	if (idx > STACK_SIZE)
	{
		stack_size *= 2;
		stack = realloc((void *)stack, sizeof(int) * stack_size);
	}
	stack[++idx] = k;
}

void	pop(int *stack)
{
	if (idx != -1)
		printf("%d\n", stack[idx--]);
	else
		printf("-1\n");
	
}

void	size(void)
{
	printf("%d\n", idx + 1);
}

void	empty(void)
{
	if (idx < 0)
		printf("1\n");
	else
		printf("0\n");
}

void	top(int *stack)
{
	if (idx >= 0)
		printf("%d\n", stack[idx]);
	else
		printf("-1\n");
}

int main(void)
{
	int	*stack = (int *)malloc(STACK_SIZE);
	int N;
	char str[10];
	scanf("%d", &N);
	for (int i = 0; i < N; ++i)
	{
		scanf("%s", &str);
		if (!strcmp(str, "push"))
		{
			int num;
			scanf("%d", &num);
			push(num, stack);
		}
		else if (!strcmp(str, "pop"))
			pop(stack);
		else if (!strcmp(str, "size"))
			size();
		else if (!strcmp(str, "empty"))
			empty();
		else if (!strcmp(str, "top"))
			top();
	}	
	return (0);
}