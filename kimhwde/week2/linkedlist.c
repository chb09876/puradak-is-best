#include<stdio.h>
#include<stdlib.h>

typedef struct Node 
{
    struct Node *next;
    int data;
}Node;



/**malloc()은 전역으로 호출 할 수 없음...와이?..상수식이라고 하던데 내가 보기에는 상수식 아니던데?...억까다.
메인함수에다가 헤드를 선언해놓고 curd 테스트케이스 만들어서 해볼 수 있을듯 **/

int main()
{
Node *list1 = malloc(sizeof(Node));//list1은 헤드임 
list1->next = NULL;
return 0;
}




// 맨 앞에다 추가하는 함수,매개변수는 첫번쨰 노드인 헤드
void append_Frist(Node *list, int newData)
{
    struct Node *newNode = malloc(sizeof(Node));
    newNode->next = list->next;
    newNode->data = newData;

    list->next = newNode;
}



// 끝에 노드추가
void append(Node *list,  int newData)
{
    if(list->next == NULL)
    {
        Node *newNode = malloc(sizeof(Node));
        newNode->data = newData;
        newNode->next = NULL;

        list->next = newNode;
    }

    else
    {
        Node *cur = list;
        while(cur->next != NULL)//마지막 노드에 도달할떄까지 반복문 돌리고
        {
            cur = cur->next;//다음 노드로 계속이동 하는거지
        }
    
    Node *newNode = malloc(sizeof(Node));
    newNode->data = newData;
    newNode->next = NULL;//NULL은 마지막 노드 다음이라고 생각하자

    cur->next = newNode;//마지막 노드에 newNode를 연결시켜준다.
    }
}



//삭제
void deletelist(Node *list)
{
    Node *cur = list;//cur을 접근한 노드라고 정의하자
    Node *next;
    while(cur != NULL)
    {
        next = cur->next;//접근한 노드의 다음 노드를 찾아놓고
        free(cur);//접근한 노드는 해제
        cur = next; //다음 노드로 접근
    }
}



//원하는 곳에 삽입
void insert(Node *list, int pos, int data)
{
    Node *cur = list;

    Node *newNode = malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;

    if(pos == 0) 
    {
        newNode->next = list->next;
        list->next = newNode;// 0번에 자리에 넣었지만 최종적으로는 1번?

    }   


    else
    {
        int count = 0;

        while(count !=pos)
        {
            if(count == (pos-1));
            {
                newNode->next = cur->next;
                cur->next = newNode;
            }
            cur = cur->next;
            count++;
        }
    }
}



//검색
Node *search_list(Node *list,int value)
{
    Node *cur = list;
    while(cur != NULL)
    {
        if(cur->data == value)
        {
            return cur;
        }
        cur = cur->next;
    }
    return NULL;//탐색실패
}

\


//수정
/** 매개변수 target자리에 search()를 사용해서 일단 수정하길 원하는 데이터를 가진 노드가 있느지 탐색해서 있으면
해당 노드의 주소를 매개변수로 받도록 한다.**/
void edit(Node *list,Node *target,int value)
{
    if(target == NULL)
    {
        printf("없어!");
    }
    else
    {
        target->data= value;
    }
}




