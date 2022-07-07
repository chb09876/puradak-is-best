#include <stdio.h>
#include <string.h>

typedef struct queue{
    int arr[10001];
    int rear;                               // queue의 맨뒤를 가르키는 변수
    int start;                              // queue의 맨앞을 가르키는 변수
} queue;

int empty(queue *s)
{
    if (s->rear == s->start )    
        return 1;                           // queue이 비어 있으면 return 1
    return 0;                               // queue에 값이 하나라도 있으면 return 0
}

int size(queue *s)
{
    return (s->rear) - (s->start);
}

void push(queue *s, int N)
{
    if (s->rear == 100001)                     // queue가 가득 차있으면 값을 안넣고 함수 종료
        return ;
    s->arr[(s->rear)++] = N;                   // queue에 값을 넣어주고 ++후위연산
}

int pop(queue *s)
{
    if(empty(s) == 1)                          // start랑 rear의 값이 같으면 start 값을 변경하면 안되기 때문에 -1 return 하고 종료
        return -1;
    return s->arr[(s->start)++];
}

int front(queue *s)
{
    if (empty(s) == 1)
        return -1;                              // 비어 있으면 -1 반환
    return s->arr[(s->start)];                  // queue의 가장 앞에 있는 값을 출력
}

int back(queue *s)
{
    if (empty(s) == 1)
        return -1;
    return s->arr[(s->rear) - 1];               // queue의 가장 뒤에 있는 값을 출력
}

int main()
{
    queue s;
    s.rear = 0;
    s.start = 0;
    int N = 0, value = 0;
    char str[10];
    scanf("%d", &N);
    for(int i = 0 ; i < N ; i++)
    {
        scanf("%s", str);
        if(strcmp(str , "push") == 0)
        {
            scanf("%d", &value);
            push(&s,value);
        }
        else if(strcmp(str , "pop") == 0)
            printf("%d\n", pop(&s));
        else if(strcmp(str , "size") == 0)
            printf("%d\n", size(&s));
        else if(strcmp(str , "empty") == 0)
            printf("%d\n", empty(&s));
        else if(strcmp(str , "front") == 0)
            printf("%d\n", front(&s));
        else if(strcmp(str , "back") == 0)
            printf("%d\n", back(&s));
    }
    return 0;
}
