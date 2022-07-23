#include<stdio.h>
#include<string.h>
#include<stdlib.h>

typedef struct{
 int max_size;
 int *arr;
 int front;
 int rear;
 int size;
} Deque;

void init(Deque *a)
{
 a -> max_size = 10;
 a -> arr= (int *)malloc(sizeof(int) * a -> max_size);
 a -> front = 0;
 a -> rear = -1;
 a -> size = 0;
}

int Is_Empty(Deque *a)
{
    if(a->size == 0)
        return 1;
    else
        return 0;
}

void push_back(Deque *a, int new_data)
{
   if(a->size == a->max_size )
   {
	int *temp;
	temp = (int*)malloc(sizeof(int)*(a->max_size*2));
	for(int k = 0; k<a->max_size; k++)
	    temp[k] = a ->arr[(a->front + k)% a->max_size];
	a ->max_size = a -> max_size *2;
	free(a ->arr);
	a -> arr = temp;
	a -> front = 0;
	a -> rear = a->size;
    }
    a->rear = (a->rear +1) % (a->max_size);
    a->arr[a->rear] = new_data;
    a -> size = a->size + 1;
}

void push_front(Deque *a, int new_data)
{
        if(a->size == a->max_size )
	    {
	    int *temp;
        int k;
        temp = (int*)malloc(sizeof(int)*(a->max_size*2));
	    for(k = 0; k<a->max_size; k++)
	          temp[k+1] = a ->arr[(a->front + k)% a->max_size];
	    a ->max_size = a -> max_size *2;
	    free(a -> arr);
	    a -> arr = temp;
        a -> front = 0;
        a -> rear = k;
        }   
        a->arr[a->front]= new_data;
        a->front = (a->front -1 + a -> max_size) % (a -> max_size); 
        ++a->size;
}

int pop_front(Deque *a)
{
    int temp = a->arr[a->front];
    a->front = (a->front + 1) % (a-> max_size);
    a ->size = a->size -1;
    return temp;
}

int pop_back(Deque *a)
{
    int temp = a->arr[a->rear];
    if(a -> rear == 0)
        a->rear = a->max_size -1;
    else
        --a->rear;
    --a->size;  
    return temp;  
}

int Front(Deque *a)
{
    return (a->arr[a->front]);
}

int Back(Deque *a)
{
    return (a->arr[a->rear]);
}

int Size(Deque *a)
{
    return (a->size);
}

int main()
{
 Deque dq;
 init(&dq);
 int n = 0;
 int num = 0;
 char s[20];

 scanf("%d", &n);

 for(int i = 0 ; i<n;i++)
 {
    scanf("%s",s);

    if(strcmp(s,"push_front") == 0)
    {
        scanf("%d", &num);
        push_front(&dq, num);

    }
    else if(strcmp(s,"push_back") == 0)
    {
        scanf("%d", &num);
        push_back(&dq, num);
    }
    else if(strcmp(s,"pop_front") == 0)
    {
	if(Is_Empty(&dq))
		printf("-1\n");
	else
		printf("%d\n",pop_front(&dq));
    }
    else if(strcmp(s,"pop_back") == 0)
    {
	if(Is_Empty(&dq))
	        printf("-1\n");
	else
		printf("%d\n",pop_back(&dq));
    }
    else if(strcmp(s, "size") == 0)
    {
        printf("%d\n",Size(&dq));
    }
    else if(strcmp(s, "empty") == 0)
    {
        if(Is_Empty(&dq))
            printf("1\n");
        else
            printf("0\n");
    }
    else if(strcmp(s, "front") == 0)
    {
        printf("%d",Front(&dq));
    }
    else if(strcmp(s, "back") == 0)
    {
        printf("%d",Back(&dq));
    }
}
  free(dq.arr);
}
