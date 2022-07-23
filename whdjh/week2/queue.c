/*원형큐에서는 front는 첫번째 요소 하나 앞, rear는 마지막 요소를 가르킨다. 따라서 삽입할때는 rear를 무조건 먼저 하나 증가시키고 증가된 위치에 삽입을 하여야하고, 삭제를 할 때도 먼저 rear를 하나 증가시키고
증가된 위치에 삽입을 하여야 하고, 삭제를 할대도 front를 증가시킨 다음 그 위치에서 데이터를 꺼내와야한다.*/
#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int *data;
    int front, rear;
    int qsize;
    int count;
} Queuetype;

//큐 초기화함수
void init_queue(Queuetype *q, int qsize)
{
    q -> data = (int *)malloc(sizeof(int) * qsize);
    q -> count = qsize;
    q -> qsize = 0;
    q -> front = q -> rear = 0;    
}

//공백
int is_empty(Queuetype *q)
{
    return (q -> front == q -> rear);
}

//포화
int is_full(Queuetype *q)
{
    return ((q -> front) == ((q -> rear + 1) % q -> count));
}

//삽입
void enqueue(Queuetype *q, int item)
{
    if(is_full(q))
    {
        int *tmp = q -> data;
        q -> data = (int *)malloc(sizeof(int) * (q -> count * 2));                                        
        for (int i = 0; i < q -> qsize; i++)                           
            q -> data[i] = tmp[(q -> front + i) % q -> count];
        free(tmp);
        q -> count *= 2;
        q -> front = 0;
        q -> rear = q -> count;
        printf("full!!!\n");
    }
    q -> rear = ((q -> rear + 1) % q -> count);
    q -> data[q -> rear] = item;    
}

//삭제
int dequeue(Queuetype *q)
{
    if(is_empty(q))
    {
        printf("empty!!!\n");
        exit(1);        //극단적조치
    }
    q -> front = ((q -> front + 1) % q -> count);
    return (q -> data[q -> front]);
}

int size(Queuetype *q)
{
    if(is_empty(q))
        printf("공백\n");
    return (q -> qsize);
}

int front(Queuetype *q)
{
    return (q -> data[q -> front]);
}

int back(Queuetype *q)
{
    if (q -> rear == 0)
        return (q -> data[q -> count - 1]);
    return (q -> data[q -> rear - 1]);
}