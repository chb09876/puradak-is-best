#include<stdio.h>
#include<string.h>
#include<stdlib.h>

typedef struct{
  int max_size;
  int *queuearr;
  int front;
  int rear;
  int size;
} Queue;

void init(Queue *a)
{
  a -> max_size = 10;
  a -> queuearr= (int *)malloc(sizeof(int) * a -> max_size);
  a -> front = 0;
  a -> rear = 0;
  a -> size = 0;
}

int Is_Empty(Queue *a)
{
    if(a->size == 0)
        return 1;
    else
        return 0;
}

void push(Queue *a, int new_data)
{
     if(a->size == a->max_size - 1)
     {
       int *temp;
       int k;
       temp = (int*)malloc(sizeof(int)*(a->max_size*2));
	   for(k = 1; k<a->max_size; k++)
       temp[k] = a ->queuearr[(a->front + k)% a->max_size];
       a -> max_size = a -> max_size *2;
       free(a ->queuearr);
       a -> queuearr = temp;
       a -> front = 0;
       a -> rear = k-1;
    }
    a->rear = (a->rear +1) % (a->max_size);
    a->queuearr[a->rear] = new_data;
    a -> size = a->size + 1;
}

void pop(Queue *a)
{
    if(Is_Empty(a))
	   printf("%d\n", -1);
    else
    {
	   a->front = (a->front + 1) % (a-> max_size);
	   printf("%d\n", a->queuearr[a->front]);
	   a ->size = a->size -1;
    }   
}

void Front(Queue *a)
{
    if(Is_Empty(a))
	printf("%d\n", -1);
    else
        printf("%d\n",a->queuearr[(a->front)+1]);
}

void Back(Queue *a)
{
    if(Is_Empty(a))
	printf("%d\n", -1);
    else
        printf("%d\n",a->queuearr[a->rear]);

}

void Size(Queue *a)
{
    printf("%d\n", a->size);
}
