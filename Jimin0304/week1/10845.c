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
    q->queuesize = 10000;
    q->front = -1;
    q->rear = -1;
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
    for (int c = 1; c <= q->queuesize; c++)
    {
        temp[c - 1] = q->elements[(q->front + c) % q->queuesize];
    }
    q->queuesize = q->queuesize * 2;
    free(q->elements);
    q->elements = temp;
    q->front = -1;
    q->rear = q->size - 1;
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

int main()
{
    Queue q;
    int N;
    char str[6];
    int item;

    Init(&q);
    scanf("%d", &N);  //명령어의 수(N)

    for (int count = 0; count < N; ++count)
    {
        scanf("%s", str);

        if (!strcmp(str, "push"))
        {
            scanf("%d", &item);
            Push(&q, item);
        }
        else if(!strcmp(str, "pop"))
        {
            printf("%d\n", Pop(&q));
        }
        else if(!strcmp(str, "empty"))
        {
            printf("%d\n", Empty(&q));
        }
        else if(!strcmp(str, "size"))
        {
            printf("%d\n", Size(&q));
        }
        else if(!strcmp(str, "front"))
        {
            printf("%d\n", Front(&q));
        }
        else if(!strcmp(str, "back"))
        {
            printf("%d\n", Back(&q));
        }
    }
    return 0;
}
