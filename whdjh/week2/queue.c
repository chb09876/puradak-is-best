/*원형큐에서는 front는 첫번째 요소 하나 앞, rear는 마지막 요소를 가르킨다. 따라서 삽입할때는 rear를 무조건 먼저 하나 증가시키고 증가된 위치에 삽입을 하여야하고, 삭제를 할 때도 먼저 rear를 하나 증가시키고
증가된 위치에 삽입을 하여야 하고, 삭제를 할대도 front를 증가시킨 다음 그 위치에서 데이터를 꺼내와야한다.*/
#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int *data;
    int front, rear;
    int qsize;       //현재 크기
    int count;          //보관 개수
} Queuetype;

void init_queue(Queuetype *q, int qsize);
int is_empty(Queuetype *q);
int is_full(Queuetype *q);
void queue_print(Queuetype *q);
void expand(Queuetype *q);
void enqueue(Queuetype *q, int item);
int dequeue(Queuetype *q);
int size(Queuetype *q);
int main();

//큐 초기화함수
void init_queue(Queuetype *q, int qsize)
{
    q -> data = (int *)malloc(sizeof(int) * qsize);
    q -> qsize = qsize;
    q -> front = q -> rear = 0;
    q -> count = 0;     //보관개수를 0으로 초기화
}

//공백
int is_empty(Queuetype *q)
{
    return (q -> front == q -> rear);
}

//포화
int is_full(Queuetype *q)
{
    return ((q -> front) == ((q -> rear + 1) % q -> qsize));
}

//출력
void queue_print(Queuetype *q)
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
void enqueue(Queuetype *q, int item)
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
int dequeue(Queuetype *q)
{
    if(is_empty(q))
    {
        printf("empty!!!\n");
        exit(1);
    }
    q -> front = ((q -> front + 1) % q -> qsize);
    return (q -> data[q -> front]);
}

//보여줄게
int size(Queuetype *q)
{
    if(is_empty(q))
        printf("공백\n");
    return (q -> data[((q -> front + 1) % (q -> qsize))]);
}


int front(Queuetype *q)
{
    return (q -> data[q -> front]);
}

int main() 
{

	Queuetype queue;

	int item = 0;
	init_queue(&queue, 6);

	enqueue(&queue, 3);
	queue_print(&queue);

	enqueue(&queue, 4);
	queue_print(&queue);

	enqueue(&queue, 5);
	queue_print(&queue);

	item = dequeue(&queue);
	queue_print(&queue);

	enqueue(&queue, 6);
	queue_print(&queue);

	enqueue(&queue, 7);
	queue_print(&queue);

	item = dequeue(&queue);
	queue_print(&queue);

	return 0;
}