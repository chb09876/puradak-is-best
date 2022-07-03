#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct
{
    int *arr;
    unsigned int reserved;
    unsigned int size;
} stack;

void init_stack(stack *s, int mem_size);
void push(stack *s, int value);
int pop(stack *s);
int size(const stack const *s);
int empty(const stack const *s);
int top(const stack const *s);
int clear(stack *s);

void init_stack(stack *s, int size)
{
    s->reserved = size;
    s->arr = (int *)malloc(sizeof(int) * size);
    s->size = 0;
}

void push(stack *s, int value)
{
    if (s->reserved == 0)
    {
        int *tmp = s->arr;
        s->arr = (int *)malloc(sizeof(int) * 2);
        s->reserved = 2;
        free(tmp);
    }
    if (s->reserved == s->size)
    { // expand memory
        int *tmp = s->arr;
        s->reserved *= 2;
        s->arr = (int *)malloc(sizeof(int) * s->reserved);
        memcpy(s->arr, tmp, s->size);
        free(tmp);
    }
    s->arr[s->size++] = value;
}

int pop(stack *s)
{
    return s->arr[--s->size];
}

int size(const stack const *s)
{
    return s->size;
}

int empty(const stack const *s)
{
    return s->size == 0;
}

int top(const stack *s)
{
    return s->arr[s->size - 1];
}

int clear(stack *s)
{
    s->size = 0;
}

int delete_stack(stack *s)
{
    free(s->arr);
    s->reserved = 0;
    s->size = 0;
}