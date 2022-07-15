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
    q->queuesize = 3;
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
    if (q->size == q->queuesize)
        return (1);
    else
        return (0);
}

void Realloc(Queue* q) 
{
    int* temp = q->elements;
    q->elements = (int*)malloc(sizeof(int) * (q->queuesize * 2));
    for (int c = 0; c < q->queuesize; c++)
        q->elements[c] = temp[(q->front + c) % q->queuesize];
    free(temp);
    q->queuesize = q->queuesize * 2;
    q->front = 0;
    q->rear = q->size;
}

void Push(Queue* q, int item)
{
    if (is_full(q) == 1) //큐가 다 찼다면
        Realloc(q);      //재할당
    q->elements[q->rear] = item;     //rear == 0부터 item을 넣음
    q->rear = (q->rear + 1) % (q->queuesize);
    ++(q->size);
    return ;
}


int Pop(Queue* q)
{
    int temp;

    if (Empty(q) == 1) //큐가 비어있다면
        return (-1);
    else
    {
        temp = q->elements[q->front];
        q->front = (q->front + 1) % (q->queuesize);
        --(q->size);
        return (temp);
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
        return (q->elements[q->front]);
}

int Back(Queue* q)
{
    if (Empty(q) == 1)
        return (-1);
    if (q->rear == 0)      //재할당이 되는 경우
        return q->elements[(q->queuesize) - 1]; 
    else
        return (q->elements[(q->rear) - 1]);
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
