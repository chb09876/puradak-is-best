#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    int *arr;
    unsigned int rear;
    unsigned int front;
    unsigned int reserved;
    unsigned int size;
} deque;

void init_deque(deque *const q, int size);
void push_front(deque *const q, int value);
void push_back(deque *const q, int value);
int pop_front(deque *const q);
int pop_back(deque *const q);
int size(const deque *const q);
int empty(const deque *const q);
int front(const deque *const q);
int back(const deque *const q);
void clear(deque *q);
void delete_deque(deque *q);

void init_deque(deque *const q, int size)
{
    q->arr = (int *)malloc(sizeof(int) * size);
    q->reserved = size;
    q->size = 0;
    q->front = 0;
    q->rear = 0;
}

void push_front(deque *const q, int value)
{
    if (q->reserved == 0)
    {
        q->arr = (int *)malloc(sizeof(int) * 2);
        q->reserved = 2;
        q->size = 0;
    }
    if (q->reserved == q->size)
    {
        int *tmp = q->arr;
        q->arr = (int *)malloc(sizeof(int) * q->reserved * 2);
        for (int i = 0; i < q->size; ++i)
            q->arr[i] = tmp[(q->front + i) % q->reserved];
        free(tmp);
        q->front = 0;
        q->rear = q->size;
        q->reserved *= 2;
    }
    if (q->front == 0)
    {
        q->arr[q->reserved - 1] = value;
        q->front = q->reserved - 1;
    }
    else
        q->arr[--q->front] = value;
    ++q->size;
}

void push_back(deque *const q, int value)
{
    if (q->reserved == 0)
    {
        q->arr = (int *)malloc(sizeof(int) * 2);
        q->reserved = 2;
        q->size = 0;
    }
    if (q->reserved == q->size)
    {
        int *tmp = q->arr;
        q->arr = (int *)malloc(sizeof(int) * q->reserved * 2);

        for (int i = 0; i < q->size; ++i)
            q->arr[i] = tmp[(q->front + i) % q->reserved];
        free(tmp);
        q->front = 0;
        q->rear = q->size;
        q->reserved *= 2;
    }
    q->arr[q->rear] = value;
    q->rear = (q->rear + 1) % q->reserved;
    ++q->size;
}

int pop_front(deque *const q)
{
    int ret = q->arr[q->front];
    q->front = (q->front + 1) % q->reserved;
    --q->size;
    return ret;
}

int pop_back(deque *const q)
{
    int ret;
    if (q->rear == 0)
    {
        ret = q->arr[q->reserved - 1];
        q->rear = q->reserved - 1;
    }
    else
        ret = q->arr[q->rear-- - 1];
    --q->size;
    return ret;
}

int size(const deque *const q)
{
    return q->size;
}

int empty(const deque *const q)
{
    return q->size == 0;
}

int front(const deque *const q)
{
    return q->arr[q->front];
}

int back(const deque *const q)
{
    if (q->rear == 0)
        return q->arr[q->reserved - 1];
    return q->arr[q->rear - 1];
}

void clear(deque *q)
{
    q->front = 0;
    q->rear = 0;
    q->size = 0;
}

void delete_deque(deque *q)
{
    free(q->arr);
    q->front = 0;
    q->rear = 0;
    q->reserved = 0;
    q->size = 0;
}