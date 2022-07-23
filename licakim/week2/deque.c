#include<stdio.h>
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
 a -> rear = 0;
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
    a->arr[a->rear] = new_data;
    a->rear = (a->rear +1) % (a->max_size);
    a -> size = a->size + 1;
}

void push_front(Deque *a, int new_data)
{
    if(a->front == 0)
    {
        a->arr[a->front] = new_data;
        a->front = a->max_size - 1;
    }
    else
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
        a->front = (a->front -1) % (a -> max_size);
    }
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
