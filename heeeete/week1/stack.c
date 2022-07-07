#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct stack{
    int *arr;
    int top2;
	int memsize;
} stack;

int empty(stack *s)
{
    if (s->top2 == 0)    
        return 1;                           // 스택이 비어 있으면 return 1
    return 0;                               // 스택에 값이 하나라도 있으면 return 0
}

int size(stack *s)
{
    return s->top2;
}

void push(stack *s, int value)
{
    if (size(s) == s->memsize)                     // 스택이 가득 차있으면 메모리 확장
    {
		s->memsize *= 2;
		s->arr = (int *)realloc(s->arr,sizeof(int) * s->memsize);
	}
    s->arr[(s->top2)++] = value;                 // 스택에 값을 넣어주고 ++후위연산
}

int pop(stack *s)
{
    if(empty(s) == 1)
        return -1;
    return s->arr[--(s->top2)];
}

int top(stack *s)
{
    if (empty(s) == 1)
        return -1;                          //비어 있으면 -1 반환
    return s->arr[(s->top2) - 1];                  //stack의 가장 위에 있는 값을 출력
}

void init(stack *s, int N)
{
    s->memsize = 2;
	s->arr = (int *)malloc(sizeof(int) * s->memsize);
	s->top2 = 0;
}

void delete_stack(stack *s)
{
	free(s->arr);
}