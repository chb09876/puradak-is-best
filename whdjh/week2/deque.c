/*덱은 전단과 후단에서 모두 삽입 삭제가 가능한 큐를 말한다.*/
/*add_front는 스택의 푸쉬, add_rear은 큐의 삽입, delete_front는 큐의 삭제, delete_rear는 스택의 팝과 같다*/
/*원형큐에서는 front는 첫번째 요소 하나 앞, rear는 마지막 요소를 가르킨다. 따라서 삽입할때는 rear를 무조건 먼저 하나 증가시키고 증가된 위치에 삽입을 하여야하고, 삭제를 할 때도 먼저 rear를 하나 증가시키고
증가된 위치에 삽입을 하여야 하고, 삭제를 할대도 front를 증가시킨 다음 그 위치에서 데이터를 꺼내와야한다.*/
#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int *data;
    int front, rear;
    int qsize;          //현재 크기
    int count;          //보관 개수
} dequetype;

void init_deque(dequetype *q, int qsize);
int is_empty(dequetype *q);
int is_full(dequetype *q);
void deque_print(dequetype *q);
void del_queue(dequetype *q);
void expand(dequetype *q);
void add_rear(dequetype *q, int item);
int delete_front(dequetype *q);
int size(dequetype *q);
int delete_rear(dequetype *q);
void add_front(dequetype *q, int val);
int main();

//큐 초기화함수
void init_deque(dequetype *q, int qsize)
{
    q -> data = (int *)malloc(sizeof(int) * qsize);
    q -> qsize = qsize;
    q -> front = q -> rear = 0;
    q -> count = 0;     //보관개수를 0으로 초기화
}

//공백
int is_empty(dequetype *q)
{
    return (q -> front == q -> rear);
}

//포화
int is_full(dequetype *q)
{
    return ((q -> front) == ((q -> rear + 1) % q -> qsize));
}

//출력
void deque_print(dequetype *q)
{
    if(is_empty(q))
    {
        printf("empty queue\n");
    }
    else
    {
        printf("queue:");
        if(!is_empty(q))
        {
            int i = q -> front;
            do {
                i = ((i + 1) % (q -> qsize));
                printf("%d | ", q -> data[i]);
                if (i == q -> rear)
                    break;
            } while (i != q -> front);
            printf("\n");
        }
    }
}

//삽입
void add_rear(dequetype *q, int item)
{
    if(is_full(q))
    {
        int *tmp = q -> data;
        q -> data = (int *)malloc(sizeof(int) * (q -> qsize * 2));                                        
        for (int i = 0; i < q -> count; i++)                           
            q -> data[i] = tmp[(q -> front + i) % q -> qsize];
        free(tmp);
        q -> qsize *= 2;
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
        q -> data = (int *)malloc(sizeof(int) * (q -> qsize * 2));                                        
        for (int i = 0; i < q -> count; i++)                           
            q -> data[i] = tmp[(q -> front + i) % q -> qsize];
        free(tmp);
        q -> qsize *= 2;
        q -> front = 0;
        q -> rear = q -> count;
        printf("full!!\n");
    }
    q -> data[q -> front] = val;
    q -> front = (q -> front - 1 + q -> qsize) % q -> qsize;
}

int delete_rear(dequetype *q)
{
    int prev = q -> rear;
    if(is_empty(q))
    {
        printf("empty!!\n");
        exit(1);
    }
    q -> rear = (q -> rear - 1 + q -> qsize) % q -> qsize;
    return (q -> data[prev]);
}

//보여줄게
int size(dequetype *q)
{
    if(is_empty(q))
        printf("공백\n");
    return (q -> data[((q -> front + 1) % (q -> qsize))]);
}


int front(dequetype *q)
{
    return (q -> data[q -> front]);
}

int main() 
{
    dequetype q;
    init_deque(&q, 100);
    printf("# ADD FRONT\n\n");
    for (int i = 0; i < 3; i++)
    {
        add_front(&q, i);
        deque_print(&q);
    }
    printf("\n# DELETE REAR\n\n");
    for (int i = 0; i < 3; i++) 
    {
        delete_rear(&q);
        deque_print(&q);
    }
    printf("\n# ADD REAR\n\n");
    for (int i = 0; i < 3; i++) 
    {
        add_rear(&q, i);
        deque_print(&q);
    }
    printf("\n# DELETE FRONT\n\n");
    for (int i = 0; i < 3; i++) 
    {
        delete_front(&q);
        deque_print(&q);
    }
    free(q.data);
    return 0;
}