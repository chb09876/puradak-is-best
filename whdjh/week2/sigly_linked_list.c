/*물리적으로 흩어져 있는 자료들을 서로 연결하여 하나로 묶는 방법을 연결 리스트라고 한다. 요소의 이동없이 줄을 이동시켜주면 된다. 그러고 이 줄이 되는 역할을 하는것이 포인터이다.*/
/*이제부터 상자를 노드라고 정의할것이다. 여기서 노드는 데이터 필드와 링크 필드로 구성되었다. 그래서 데이터필드에는 우리가 저장하고 싶은 데이터가 저장된다. 첫번째 노드를 헤드 마지막노드를 널로 정의하자*/
#include <stdio.h>
#include <stdlib.h>

//노드정의
typedef struct listnode {
    int data;
    struct listnode *link;  //링크노드를 가르키는 포인터로 정의되며 다음 노드의 주소가 된다.
} listnode;

//노드생성함수
listnode* init_node(int data)
{
    listnode *head = (listnode *)malloc(sizeof(listnode));
    head -> data = data;
    head -> link = NULL;
    return (head);
}

//리스트의 맨 처음에 항목을 추가하는 함수, 리스트에 빈공간이 없으면 오류를 발생한다.
listnode* insert_first(listnode *head, int value)                //단순 연결 리스트는 헤드 포링터만 있으면 된다.
{
    listnode *p = (listnode *)malloc(sizeof(listnode));     //동적할당을 통해 새로운 노드 p를 생성한다.
    p -> data = value;                                      //p -> data에 value를 저장한다.
    p -> link = head;                                       //p -> link를 현재 head로 변경해서 저장한다.
    head = p;                                               //head를 p값으로 변경한다.
    return (head);
}

//임의의 위치에 삽입하는 함수
listnode* insert(listnode *head, listnode *pre, int value) //pre는 선행노드르 가르키고 있음
{
    listnode *p = (listnode *)malloc(sizeof(listnode));         //새로운 노드를 생성하여 변수 p를 가르킨다.
    p -> data = value;                                          //p의 데이터 필드에 value을 저장한다.
    p -> link = pre -> link;                                    //p의 링크 필드에 pre노드를 가르키고 있던 값으로 변경한다.
    pre -> link = p;                                            //가르키고 있었던 값이 값을 저장한 값을 가르키게 한다.
    return (head);
}

//리스트의 첫번째 항목을 삭제하는 함수
listnode* delete_first(listnode *head)
{
    listnode *remove;
    if(head == NULL) 
        return 0;
    remove = head;              //헤드포인터의 값을 remove에 복사
    head = remove -> link;      //헤드 포인터의 값을 head -> link로 변경
    free(remove);
    return (head);
}

//삭제하는 함수
listnode* delete(listnode *head, listnode *pre)
{
    listnode *remove;
    remove = pre -> link;
    pre -> link = remove -> link;
    free(remove);
    return (head);
}

//노드를 출력시켜 보여준다.
void print_list(listnode *head)
{
    for(listnode *p = head; p != NULL; p = p -> link)
        printf("%d ->", p -> data);
    printf("null\n");
}

//검색하는 함수
listnode* search_list(listnode *head, int x)
{
    listnode *p = head;

    while(p != NULL)
    {
        if(p -> data == x)
            return p;
        p = p -> link;
    }
    return 0;
}

//수정하는 함수
void edit(listnode *head, int x)
{
    head -> data = x;
}

int main()
{
    listnode *head = NULL;
    for(int i = 0; i < 5; i++)
    {
        head = insert_first(head, i);
        print_list(head);
    }
    for(int i = 0; i < 5; i++)
    {
        head = delete_first(head);
        print_list(head);
    }
    printf("\n\n");
    if(search_list(head, 3) != NULL)
        printf("find3\n");
    else
        printf("nofind3\n");
    printf("\n\n");
    return 0;
}

/* edit용
int main()
{
    listnode* head = NULL;

    head = insert_first(head, 10);
    print_list(head);
    edit(head, 40);
    print_list(head);
    return 0;
    
}
*/ 