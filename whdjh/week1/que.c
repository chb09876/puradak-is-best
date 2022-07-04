#include "stdio.h"
#include "string.h"
#define MAX_QUE_SIZE 10000

int queue[MAX_QUE_SIZE];            //큐 배열
int i_front = -1, i_rear = -1;      //front와 rear의 인덱스, 전역 변수 선언으로 자동으로 -1로 초기화

//넣기
void push(int item) 
{
    queue[++i_rear] = item;
}

//빼기
int pop() 
{
    if(i_front == i_rear) 
        return -1;
    else
        return (queue[++i_front]);
}

//큐에 있는 정수
int size() 
{
    return (i_rear - i_front);
}

//비어있는지 확인
int is_empty() 
{
    if(i_front == i_rear)
        return 1;
    else
        return 0;
}

//큐 가장 앞에 있는 정수
int front()
{
    if(i_front == i_rear)           //인덱스가 -1 이므로 정수가 없음
        return -1;
    else
        return (queue[i_front + 1]);
}

//큐 가장 뒤에 있는 정수
int rear() 
{
    if(i_front == i_rear)           //인덱스가 -1 이므로 정수가 없음
        return -1;
    else
        return (queue[i_rear]);
}

int main()
{
    int n;
    scanf("%d", &n);

    for(int i = 0; i < n; i++)
    {
        char cmd[10];
        scanf("%s", cmd);

        if(!strcmp(cmd, "push"))
        {
            int item;
            scanf("%d\n", &item);
            push(item);
        }

        else if(!strcmp(cmd, "pop"))
            printf("%d\n", pop());

        else if(!strcmp(cmd, "size"))
            printf("%d\n", size());

        else if(!strcmp(cmd, "empty"))
            printf("%d\n", is_empty());
            
        else if(!strcmp(cmd, "front"))
            printf("%d\n", front());

        else
            printf("%d\n", rear());
    }
    return 0;
}