#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct Deque {
    int* elements;
    int queuesize;
    int front;
    int rear;
    int size;
} Deque;

void Init(Deque* q){
    q->queuesize = 3;
    q->front = 0;
    q->rear = 0;
    q->size = 0;
    q->elements = (int*)malloc(sizeof(int) * q->queuesize);
}

int Empty(Deque* q)
{
    if (q->size == 0)
        return (1);
    else
        return (0);
}

int is_full(Deque* q)
{
    if (q->size == q->queuesize)
        return (1);
    else
        return (0);
}

void Realloc(Deque* q) 
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

void PushFront(Deque* q, int item)
{
    if (is_full(q) == 1) //큐가 다 찼다면
        Realloc(q);      //재할당
    q->front = (q->front - 1 + q->queuesize) % (q->queuesize); //-1부터 삽입
    q->elements[q->front] = item;
    ++(q->size);
    return ;
}

void PushBack(Deque* q, int item)
{
    if (is_full(q) == 1) //큐가 다 찼다면
        Realloc(q);      //재할당
    q->elements[q->rear] = item;     //0부터 삽입
    q->rear = (q->rear + 1) % (q->queuesize);
    ++(q->size);
    return ;
}

int PopFront(Deque* q)
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

int PopBack(Deque* q)
{
    if (Empty(q) == 1) //큐가 비어있다면
        return (-1);
    else
    {
        q->rear = (q->rear - 1 + q->queuesize) % (q->queuesize);
        --(q->size);
        return (q->elements[q->rear]);
    }
}

int Size(Deque* q)
{
    return (q->size);
}

int Front(Deque* q)
{
    if (Empty(q) == 1)
        return (-1);
    else
        return (q->elements[q->front]);
}

int Back(Deque* q)
{
    if (Empty(q) == 1)
        return (-1);
    if (q->rear == 0)      //재할당이 되는 경우
        return q->elements[(q->queuesize) - 1]; 
    else
        return (q->elements[(q->rear - 1 + q->queuesize) % q->queuesize]);
}

int main()
{
    Deque q;
    int N;
    char str[15];
    int item;

    Init(&q);
    scanf("%d", &N);  //명령어의 수(N)

    for (int count = 0; count < N; ++count)
    {
        scanf("%s", str);

        if (!strcmp(str, "push_front"))
        {
            scanf("%d", &item);
            PushFront(&q, item);
        }
        if (!strcmp(str, "push_back"))
        {
            scanf("%d", &item);
            PushBack(&q, item);
        }
        else if(!strcmp(str, "pop_front"))
        {
            printf("%d\n", PopFront(&q));
        }
        else if(!strcmp(str, "pop_back"))
        {
            printf("%d\n", PopBack(&q));
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
