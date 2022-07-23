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
int size(const stack *const s);
int empty(const stack *const s);
int top(const stack *const s);
void clear(stack *s);
void delete_stack(stack *s);

void init_stack(stack *s, int mem_size)
{
    s->arr = (int *)malloc(sizeof(int) * mem_size);
    s->reserved = mem_size;
    s->size = 0;
}

void push(stack *s, int value)
{
    if (s->reserved == 0)
    {
        s->arr = (int *)malloc(sizeof(int) * 2);
        s->reserved = 2;
    }
    if (s->reserved == s->size)
    { // expand memory
        int *tmp = s->arr;
        s->reserved *= 2;
        s->arr = (int *)malloc(sizeof(int) * s->reserved);
        memcpy(s->arr, tmp, s->size * sizeof(int));
        free(tmp);
    }
    s->arr[s->size++] = value;
}

int pop(stack *s)
{
    return s->arr[--s->size];
}

int size(const stack *const s)
{
    return s->size;
}

int empty(const stack *const s)
{
    return s->size == 0;
}

int top(const stack *const s)
{
    return s->arr[s->size - 1];
}

void clear(stack *s)
{
    s->size = 0;
}

void delete_stack(stack *s)
{
    free(s->arr);
    s->reserved = 0;
    s->size = 0;
}

int main()
{
    int N;
    stack s;
    init_stack(&s, 3);
    scanf("%d", &N);
    for (int i = 0; i < N; ++i)
    {
        char command[6];
        scanf("%s", command);
        if (!strcmp(command, "push"))
        {
            int value;
            scanf("%d", &value);
            push(&s, value);
        }
        else if (!strcmp(command, "pop"))
        {
            if (empty(&s))
                printf("%d\n", -1);
            else
                printf("%d\n", pop(&s));
        }
        else if (!strcmp(command, "size"))
        {
            printf("%d\n", size(&s));
        }
        else if (!strcmp(command, "empty"))
        {
            printf("%d\n", empty(&s));
        }
        else if (!strcmp(command, "top"))
        {
            if (empty(&s))
                printf("%d\n", -1);
            else
                printf("%d\n", top(&s));
        }
    }
    delete_stack(&s);
}