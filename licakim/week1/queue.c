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
  a -> rear = -1;
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
<<<<<<< HEAD
   	if(a->size == a->max_size )
	{
	   int *temp;
       int k;
       temp = (int*)malloc(sizeof(int)*(a->max_size*2));
	   for(k = 0; k<a->max_size; k++)
	       temp[k] = a ->queuearr[(a->front + k)% a->max_size];
	   a ->max_size = a -> max_size *2;
	   free(a ->queuearr);
	   a -> queuearr = temp;
       a -> front = 0;
       a -> rear = k-1;
    }
    a->queuearr[a->rear] = new_data;
    a->rear = (a->rear +1) % (a->max_size);
	a -> size = a->size + 1;
=======
     if(a->size == a->max_size)
     {
       int *temp;
       int k;
       temp = (int*)malloc(sizeof(int)*(a->max_size*2));
	   for(k = 0; k<a->max_size; k++)
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
>>>>>>> 41dcd070ceee5a5b2fe82fd1950865e8269f6fb0
}

int pop(Queue *a)
{
<<<<<<< HEAD
	int temp = a->queuearr[a->front];
    a->front = (a->front + 1) % (a-> max_size);
	a ->size = a->size -1;
	return temp;   
=======
    if(Is_Empty(a))
	   printf("%d\n", -1);
    else
    {
	   printf("%d\n", a->queuearr[a->front]);
	   a->front = (a->front + 1) % (a-> max_size);
	   a ->size = a->size -1;
    }   
>>>>>>> 41dcd070ceee5a5b2fe82fd1950865e8269f6fb0
}

int Front(Queue *a)
{
<<<<<<< HEAD
    return (a->queuearr[a->front]);
}	

int Back(Queue *a)
{
    return (a->queuearr[a->rear]);
=======
    if(Is_Empty(a))
	printf("%d\n", -1);
    else
        printf("%d\n",a->queuearr[a->front]);
>>>>>>> 41dcd070ceee5a5b2fe82fd1950865e8269f6fb0
}

int Size(Queue *a)
{
<<<<<<< HEAD
    return (a->size);
=======
    if(Is_Empty(a))
	printf("%d\n", -1);
    else
        printf("%d\n",a->queuearr[a->rear]);

>>>>>>> 41dcd070ceee5a5b2fe82fd1950865e8269f6fb0
}

