#include<stdio.h>
#include<stdlib.h>

typedef struct node
{
    int data;
    struct node *next;
} node;

typedef struct list
{
    node *head;
} list;

void init(list *a)
{
    a->head = malloc(sizeof(node));
    a->head->next = NULL;
    a->head->data = 0;//data의 개수
    return;
}

int size(list*a)
{
    return a->head->data;
}

int is_empty(list*a)
{
    if(a->head->data==0)
        return 1;
    else
        return 0;
}

//노드 삽입
void insert(list *a, int new_data)
{
    node *n=malloc(sizeof(node));
    n ->data = new_data;
    node *cnt = a->head;
    for(int i = 0; i < a->head->data;i++)
    {
        cnt = cnt->next;
    }
    cnt->next = n;
    n ->next = NULL;
    a->head->data ++;
    return;
}

//노드 삭제
void delete(list *a, int d_data)
{
  node *cnt = a->head;
  while(cnt->next != NULL)
  {
    if(cnt->next->data == d_data)
    {
        node *temp = cnt->next;
        cnt->next= cnt->next->next;
        free(temp);
        break;
    }
    cnt = cnt ->next;
  }   
    a->head->data --;
    return ;
}

//노드 검색
node* search(list *a, int s_data)
{
    node *cnt = a->head; 
    while(cnt->next != NULL)
    {
        if(cnt->next->data == s_data)
        {
            return cnt->next;
        }
        cnt = cnt -> next;
    }   
    return NULL;
}

//노드 수정
void modify(list*a,int n,int new_data)
{
    if(a->head->data >= n)
    {
        node* cnt = a->head;
        for(int i=0; i<n; i++)
        {
            cnt = cnt -> next;
        }
        cnt->data = new_data;
        return;
    }
}

int main()
{
    list l;
    init(&l);

    insert(&l, 1);
    printf("%d\n",size(&l));
    insert(&l, 2);
    printf("%d\n",size(&l));
    insert(&l, 3);
    printf("%d\n",size(&l));
    insert(&l, 4);
    node *tmp = search(&l,2);
	printf("%d\n",tmp->data);
    delete(&l, 3);
	modify(&l,2,5);
    node *temp = l.head->next;
    while(temp != NULL)
    {
        printf("%d\n",temp->data);
        temp = temp ->next;
    }
}

