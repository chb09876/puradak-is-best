#include "stdio.h"
#include "string.h"
#define MAX_STACK_SIZE 10000

int stack[MAX_STACK_SIZE];      //스택 배열
int i_top = -1;                 //인덱스 top, 전역 변수 선언으로 자동으로 -1로 초기화

//넣기
void push(int item)
{
    stack[++i_top] = item;
}

//빼기
int pop()
{
    if(is_empty())
        return -1;
    return (stack[i_top--]);
}

//스택에 있는 정수
int size()
{
    return (i_top + 1);         //인덱스가 0부터 시작해서 +1 해야됨
}

//비어있는지 확인
int is_empty()
{
    if(i_top == -1)
        return 1;
    else
        return 0;
}

//가장 위에 있는게 무엇인가?
int top()
{
    if(i_top == -1)
        return -1;
    return (stack[i_top]);
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
            
        else if(!strcmp(cmd, "top"))
            printf("%d\n", top());
    }
    return 0;
}