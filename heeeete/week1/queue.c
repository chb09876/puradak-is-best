#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct queue{
    int *arr;
    int rear;                               // queue의 맨뒤를 가르키는 변수
    int start;                              // queue의 맨앞을 가르키는 변수
	int max_size;
    int size;
} queue;

int empty(queue *s)
{
    if (s->size == 0)    
        return 1;                           // 스택이 비어 있으면 return 1
    return 0;                               // 스택에 값이 하나라도 있으면 return 0
}

int full(queue *s)
{
    if(s->size == s->max_size)
        return 1;
    return 0;
}

int size(queue *s)
{
    return s->size;
}

void Realloc(queue *s)
{
    int *temp = s->arr;
    s->arr = (int *)malloc(sizeof(int) * (s->max_size * 2));
    for(int i = 0 ; i < s->max_size ; i++)
        s->arr[i] = temp[(s->start + i) % s->max_size];
    free(temp);
    s->start = 0;
    s->rear = s->size;
    s->max_size *= 2;
}

void push(queue *s, int value)
{
	if (full(s))
        Realloc(s);
    s->size += 1;
    s->arr[s->rear++] = value;
    s->rear = s->rear % s->max_size;
}

int pop(queue *s)
{
    if(empty(s))
        return -1;
    int start = s->start;
    s->start = (s->start + 1) % s->max_size;
    s->size -= 1;
    return s->arr[start];
}

int front(queue *s)
{
    if (empty(s))
        return -1;
    return s->arr[(s->start)];                  //stack의 가장 위에 있는 값을 출력
}

int back(queue *s)
{
    if (empty(s))
        return -1;
    if (s->rear == 0)
        return s->arr[s->max_size - 1];
    return s->arr[(s->rear) - 1];
}

void init(queue *s)
{
	s->max_size = 2;
	s->arr = (int *)malloc(sizeof(int) * s->max_size);
	s->rear = 0;
	s->start = 0;
    s->size = 0;
}

void queue_delete(queue *s)
{
	free(s->arr);
}

int main()
{
    queue s;
    int N = 0, value = 0;
    char str[10];
    scanf("%d", &N);
	init(&s);
    for(int i = 0 ; i < N ; i++)
    {
        scanf("%s", str);
        if(strcmp(str , "push") == 0)
        {
            scanf("%d", &value);
            push(&s,value);
        }
        else if(strcmp(str , "pop") == 0)
            printf("%d\n", pop(&s));
        else if(strcmp(str , "size") == 0)
            printf("%d\n", size(&s));
        else if(strcmp(str , "empty") == 0)
            printf("%d\n", empty(&s));
        else if(strcmp(str , "front") == 0)
            printf("%d\n", front(&s));
        else if(strcmp(str , "back") == 0)
            printf("%d\n", back(&s));
    }
    return 0;
}