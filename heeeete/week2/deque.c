#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct deque{
    int *arr;
    int rear;
    int start;
	int max_size;
    int size;
} deque;

int empty(deque *s)
{
    if (s->size == 0)    
        return 1;
    return 0;
}

int full(deque *s)
{
    if(s->size == s->max_size)
        return 1;
    return 0;
}

int size(deque *s)
{
    return s->size;
}

void Realloc(deque *s)
{
    int *temp = s->arr;
    s->arr = (int *)malloc(sizeof(int) * (s->max_size * 2));
    for(int i = 0 ; i < s->size ; i++)
        s->arr[i] = temp[(s->start + i) % s->max_size];
    free(temp);
    s->max_size *= 2;
    s->start = 0;
    s->rear = s->size;
}

void push_front(deque *s, int value)
{
    if (full(s))
        Realloc(s);
    s->size += 1;
    s->start = (s->start - 1 + s->max_size) % s->max_size;
    s->arr[s->start] = value;
}

void push_back(deque *s, int value)
{
	if (full(s))
        Realloc(s);
    s->size += 1;
    s->arr[s->rear] = value;
    s->rear = (s->rear + 1) % s->max_size;
}

int pop_back(deque *s)
{
    if(empty(s))
        return -1;
    s->rear = (s->rear - 1 + s->max_size) % s->max_size;
    s->size -= 1;
    return s->arr[s->rear];
}

int pop_front(deque *s)
{
    if(empty(s))
        return -1;
    int start = s->start;
    s->start = (s->start + 1) % s->max_size;
    s->size -= 1;
    return s->arr[start];
}

int front(deque *s)
{
    if (empty(s))
        return -1;
    return s->arr[s->start];
}

int back(deque *s)
{
    if (empty(s))
        return -1;
    return s->arr[(s->rear - 1 + s->max_size) % s->max_size];
}

void init(deque *s)
{
	s->max_size = 4;
	s->arr = (int *)malloc(sizeof(int) * s->max_size);
	s->rear = 0;
	s->start = 0;
    s->size = 0;
}

void deque_delete(deque *s)
{
	free(s->arr);
}

int main()
{
    deque s;
    int N = 0, value = 0;
    char str[11];
    scanf("%d", &N);
	init(&s);
    for(int i = 0 ; i < N ; i++)
    {
        scanf("%s", str);
        if(strcmp(str , "push_back") == 0)
        {
            scanf("%d", &value);
            push_back(&s,value);
        }
        else if(strcmp(str , "push_front") == 0)
        {
            scanf("%d", &value);
            push_front(&s,value);
        }
        else if(strcmp(str , "pop_front") == 0)
            printf("%d\n", pop_front(&s));
        else if(strcmp(str , "pop_back") == 0)
            printf("%d\n", pop_back(&s));
        else if(strcmp(str , "size") == 0)
            printf("%d\n", size(&s));
        else if(strcmp(str , "empty") == 0)
            printf("%d\n", empty(&s));
        else if(strcmp(str , "front") == 0)
            printf("%d\n", front(&s));
        else if(strcmp(str , "back") == 0)
            printf("%d\n", back(&s));
    }
    free(s.arr);

    return 0;
}