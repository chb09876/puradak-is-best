#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct
{
    int *arr;
    unsigned int rear;
    unsigned int front;
    unsigned int reserved;
    unsigned int size;
} queue;

void init_queue(queue *const q, int size);
void push(queue *const q, int value);
int pop(queue *const q);
int size(const queue *const q);
int empty(const queue *const q);
int front(const queue *const q);
int back(const queue *const q);
void clear(queue *q);
void delete_queue(queue *q);

void init_queue(queue *const q, int size)
{
    q->arr = (int *)malloc(sizeof(int) * size);
    q->reserved = size;
    q->size = 0;
    q->front = 0;
    q->rear = 0;
}

void push(queue *const q, int value)
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

int pop(queue *const q)
{
    int ret = q->arr[q->front];
    q->front = (q->front + 1) % q->reserved;
    --q->size;
    return ret;
}

int size(const queue *const q)
{
    return q->size;
}

int empty(const queue *const q)
{
    return q->size == 0;
}

int front(const queue *const q)
{
    return q->arr[q->front];
}

int back(const queue *const q)
{
    if (q->rear == 0)
        return q->arr[q->reserved - 1];
    return q->arr[q->rear - 1];
}

void clear(queue *q)
{
    q->front = 0;
    q->rear = 0;
    q->size = 0;
}

void delete_queue(queue *q)
{
    free(q->arr);
    q->front = 0;
    q->rear = 0;
    q->reserved = 0;
    q->size = 0;
}