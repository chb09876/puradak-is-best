/*덱은 전단과 후단에서 모두 삽입 삭제가 가능한 큐를 말한다.*/
/*add_front는 스택의 푸쉬, add_rear은 큐의 삽입, delete_front는 큐의 삭제, delete_rear는 스택의 팝과 같다*/
/*원형큐에서는 front는 첫번째 요소 하나 앞, rear는 마지막 요소를 가르킨다. 따라서 삽입할때는 rear를 무조건 먼저 하나 증가시키고 증가된 위치에 삽입을 하여야하고, 삭제를 할 때도 먼저 rear를 하나 증가시키고
증가된 위치에 삽입을 하여야 하고, 삭제를 할대도 front를 증가시킨 다음 그 위치에서 데이터를 꺼내와야한다.*/
#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int *data;
    int front, rear;
    int qsize;  
    int count;         
} dequetype;

//큐 초기화함수
void init_deque(dequetype *q, int qsize)
{
    q -> data = (int *)malloc(sizeof(int) * qsize);
    q -> count = qsize;
    q -> qsize = 0;
    q -> front = q -> rear = 0;    
}

//공백
int is_empty(dequetype *q)
{
    return (q -> front == q -> rear);
}

//포화
int is_full(dequetype *q)
{
    return ((q -> front) == ((q -> rear + 1) % q -> count));
}

//삽입
void add_rear(dequetype *q, int item)
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
    q -> rear = ((q -> rear + 1) % q -> qsize);
    q -> data[q -> rear] = item;    
}

//삭제
int delete_front(dequetype *q)
{
    if(is_empty(q))
    {
        printf("empty!!!\n");
        exit(1);
    }
    q -> front = ((q -> front + 1) % q -> qsize);
    return (q -> data[q -> front]);
}

void add_front(dequetype *q, int val)
{
    if(is_full(q))
    {        
        int *tmp = q -> data;
        q -> data = (int *)malloc(sizeof(int) * (q -> count * 2));                                        
        for (int i = 0; i < q -> qsize; i++)                           
            q -> data[i] = tmp[(q -> front + i) % q -> count];
        free(tmp);
        q -> qsize *= 2;
        q -> front = 0;
        q -> rear = q -> count;
        printf("full!!\n");
    }
    q -> data[q -> front] = val;
    q -> front = (q -> front - 1 + q -> count) % q -> count;
}

int delete_rear(dequetype *q)
{
    int prev = q -> rear;
    if(is_empty(q))
    {
        printf("empty!!\n");
        exit(1);
    }
    q -> rear = (q -> rear - 1 + q -> count) % q -> count;
    return (q -> data[prev]);
}

//보여줄게
int size(dequetype *q)
{
    if(is_empty(q))
        printf("공백\n");
    return (q -> qsize);
}

int front(dequetype *q)
{
    return (q -> data[q -> front]);
}

int back(dequetype *q)
{
    if (is_empty(q))
        return (q -> data[q -> count - 1]);
    return (q -> data[q -> rear -1]);
}