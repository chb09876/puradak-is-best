#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct Queue {
    int* elements;
    int queuesize;
    int front;
    int rear;
    int size;
} Queue;

void Init(Queue* q){
    q->queuesize = 10;
    q->front = 0;
    q->rear = 0;
    q->size = 0;
    q->elements = (int*)malloc(sizeof(int) * q->queuesize);
}

int Empty(Queue* q)
{
    if (q->size == 0)
        return (1);
    else
        return (0);
}

int is_full(Queue* q)
{
    if (q->size == q->queuesize - 1)
        return (1);
    else
        return (0);
}

void Realloc(Queue* q)   //realloc을 하는 과정에서 에러 발생
{
    int* temp;
    temp = (int*)malloc(sizeof(int) * (q->queuesize * 2));
    for (int c = 0; c < q->queuesize; c++)
    {
        temp[c] = q->elements[q->front + c];
    }
    q->queuesize = q->queuesize * 2;
    free(q->elements);
    q->elements = temp;
    q->front = 0;
    q->rear = q->size;
}

void Push(Queue* q, int item)
{
    if (is_full(q) == 1) //큐가 다 찼다면
        Realloc(q);      //재할당
    q->rear = (q->rear + 1) % (q->queuesize);
    q->elements[q->rear] = item;
    ++(q->size);
    return ;
}


int Pop(Queue* q)
{
    if (Empty(q) == 1) //큐가 비어있다면
        return (-1);
    else
    {
        q->front = (q->front + 1) % (q->queuesize);
        --(q->size);
        return (q->elements[q->front]);
    }
}

int Size(Queue* q)
{
    return (q->size);
}

int Front(Queue* q)
{
    if (Empty(q) == 1)
        return (-1);
    else
        return (q->elements[q->front + 1]);
}

int Back(Queue* q)
{
    if (Empty(q) == 1)
        return (-1);
    else
        return (q->elements[q->rear]);
}
