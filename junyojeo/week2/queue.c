#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct node
{
	int				data;
	struct	node	*next;
}node;

typedef struct queue
{
	node	*first, *last;
	int		cnt;
}queue;

void	init(queue *q);
void	empty(queue *q);
void	push(int data, queue *q);
void	pop(queue *q);
void	size(queue *q);
void	front(queue *q);
void	back(queue *q);
void	q_delete(queue *q);

void	init(queue *q)
{
	q->first = NULL;
	q->last = NULL;
	q->cnt = 0;
}

void	empty(queue *q)
{
	if (q->first == NULL)
		printf("1\n");
	else
		printf("0\n");
}

void	push(int X, queue *q)//임시 노드 tmp에 X가 들어가고 first, last를 새 노드에 맞게 설정 후 last의 다음 노드에 first를 연결해준다.
{
	node	*tmp = (node *)malloc(sizeof(node));
	tmp->data = X;
	if (q->first == NULL)//큐가 비어있으면 first, last의 값을 새 노드로 바꿔준다.
	{
		q->first = tmp;
		q->last = tmp;
	}
	else//큐가 비어있지 않으면 last의 다음 노드에 tmp를 집어넣고 last는 tmp를 가르킨다.
	{
		q->last->next = tmp;
		q->last = tmp;
	}
	q->last->next = q->first;//마지막 노드는 다시 첫번째 노드를 가르킨다.[원형큐]
	q->cnt++;
}

void	pop(queue *q)//임시 노드 tmp에 first의 주소가 들어가고 
{
	if (q->first == NULL)
		printf("-1\n");
	else
	{
		node	*tmp = q->first;
		int		X = q->first->data; //printf("%d")에서 매개변수로 q->first->data는 const char *형이기 때문에 받을 수 없어서 int형으로 바꿔 넣어준다.
		printf("%d\n", X);
		if (q->first == q->last)//first, last가 같은 주소이면==>first가 pop되면 last는 변하지 않아서 같이 NULL로 초기화.
			init(q);
		else
		{
			q->first = q->first->next;
			q->last->next = q->first;//last의 next인 first가 옮겨가니까 다시 묶어준다.
			q->cnt--;
		}
		free(tmp);
	}
}

void	size(queue *q)
{
	printf("%d\n", q->cnt);
}

void	front(queue *q)
{
	if (q->first == NULL)
		printf("-1\n");
	else
	{
		int	data = q->first->data;
		printf("%d\n", data);
	}
}

void	back(queue *q)
{
	if (q->first == NULL)
		printf("-1\n");
	else
	{
		int	data = q->last->data;
		printf("%d\n", data);
	}
}

void	q_delete(queue *q)//pop과 비슷하게 동작하지만 노드의 data만 삭제한다.
{
	if (q->first == NULL)
		printf("-1\n");
	node	*tmp = q->first;
	if(q->first == q->last)
		init(q);
	else//first 옮겨주고 last 묶어주고 first가 저장 되어있던 tmp 삭제. 
	{
		q->first = q->first->next;
		q->last->next = q->first;
	}
	free(tmp);
}

int main(void)
{
	char	str[10];
	queue	*q;
	int		N;

	q = malloc(sizeof(queue));
	init(q);
	scanf("%d", &N);
	for (int i = 0; i < N; ++i)
	{
		scanf("%s", str);
		if (!strcmp(str, "push"))
		{
			int X;
			scanf("%d", &X);
			push(X, q);
		}
		else if (!strcmp(str, "pop"))
			pop(q);
		else if (!strcmp(str, "size"))
			size(q);
		else if (!strcmp(str, "empty"))
			empty(q);
		else if (!strcmp(str, "front"))
			front(q);
		else if (!strcmp(str, "back"))
			back(q);
		else if (!strcmp(str, "q_delete"))
			q_delete(q);
	}
	return (0);
}
