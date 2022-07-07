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

void push(queue *s, int value)
{
	if (full(s))
    {
	    (s->max_size) *= 2;
	   	s->arr = (int *)realloc(s->arr, sizeof(int) * (s->max_size)); 
    }
    ㅈㅈ;
    s->arr[s->rear++] = value;                   // 스택에 값을 넣어주고 ++후위연산
    s->size += 1;
}

int pop(queue *s)
{
	if(empty(s))                             //비어있으면 -1 return
		return -1;
    s->size -= 1;
    return s->arr[(s->start)++];
}

int front(queue *s)
{
    if (empty(s) == 1)
        return -1;                          //비어 있으면 -1 반환
    return s->arr[(s->start)];                  //stack의 가장 위에 있는 값을 출력
}

int back(queue *s)
{
    if (empty(s) == 1)
        return -1;
    s->size -= 1;
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
	queue_delete(&s);
    return 0;
}