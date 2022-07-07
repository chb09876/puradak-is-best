#include <stdio.h>
#include <string.h>

int	stack[10001];
int	idx = -1;

void	push(int k)
{
	stack[++idx] = k;
}

void	pop(void)
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

void	top(void)
{
	if (idx >= 0)
		printf("%d\n", stack[idx]);
	else
		printf("-1\n");
}

int main(void)
{
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
			push(num);
		}
		else if (!strcmp(str, "pop"))
			pop();
		else if (!strcmp(str, "size"))
			size();
		else if (!strcmp(str, "empty"))
			empty();
		else if (!strcmp(str, "top"))
			top();
	}	
	return (0);
}