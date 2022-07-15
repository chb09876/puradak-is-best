#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct {
    int *data;
    int capacity; //현재 크기
    int i_top;
} StackType;

//스택 생성 함수
void init_stack(StackType *s)
{
    s -> i_top = -1;
    s -> capacity = 1;
    s -> data = (int *)malloc(s -> capacity * sizeof(int));
}

//공백
int is_empty(StackType *s)
{
    return (s -> i_top == -1);
}

//포화
int is_full(StackType *s)
{
    return (s -> i_top == (s -> capacity - 1));
}

//삽입
void push(StackType *s, int item)
{
    if(is_full(s))
    {
        s -> capacity *= 2;
        s -> data = (int *)realloc(s -> data, s -> capacity * sizeof(int));
    }
    s -> data[++(s -> i_top)] = item;
}

//삭제
int pop(StackType *s)
{
    if(is_empty(s))
    {
        return -1;
    }
    else
        return (s -> data[(s -> i_top)--]);
}

int size(StackType *s)
{
    return (s -> i_top + 1);         //인덱스가 0부터 시작해서 +1 해야됨
}

int top(StackType *s)
{
    if(is_empty(s))
        return -1;
    return (s -> data[s -> i_top]);
}
//잘못된 접근은 사용자 책임으로
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