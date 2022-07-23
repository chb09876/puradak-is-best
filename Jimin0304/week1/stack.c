#include <stdlib.h>

typedef struct Stack {
    int* elements;
    int stacksize;
    int size;
} Stack;

void Init(Stack* s){
    s->stacksize = 10;
    s->size = 0;
    s->elements = (int*)malloc(sizeof(int) * s->stacksize);
}

int Empty(Stack* s)
{
    if (s->size == 0)
        return (1);
    else
        return (0);
}

int is_full(Stack* s)
{
    if (s->size == s->stacksize)
        return (1);
    else
        return (0);
}

void Realloc(Stack* s)
{
    int* temp;
    temp = (int*)malloc(sizeof(int) * (s->stacksize * 2));
    for (int c = 0; c < s->stacksize; c++)
    {
        temp[c] = s->elements[c];
    }
    s->stacksize = s->stacksize * 2;
    free(s->elements);
    s->elements = temp;
}

void Push(Stack* s, int item)
{
    if (is_full(s) == 1) //스택이 다 찼다면
        Realloc(s);      //재할당
    s->elements[(s->size)++] = item;
        return ;
}


int Pop(Stack* s)
{
    if (Empty(s) == 1) //스택이 비어있다면
        return (-1);
    else
        return (s->elements[--(s->size)]);
}

int Size(Stack* s)
{
    return (s->size);
}

int Top(Stack* s)
{
    if (s->size == 0)
        return (-1);
    else
        return (s->elements[(s->size)-1]);
}
