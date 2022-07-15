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
   	if(a->size == a->max_size)
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
	a -> rear = (a->rear +1) % (a->max_size);
	a -> queuearr[a->rear] = new_data;
	a -> size = a->size + 1;
}

void pop(Queue *a)
{
	if(Is_Empty(a))
	      printf("%d\n", -1);
    else
    {
		printf("%d\n", a->queuearr[a->front]);
		a->front = (a->front + 1) % (a-> max_size);
		a ->size = a->size -1;
    }   
}

void Front(Queue *a)
{
    if(Is_Empty(a))
	      printf("%d\n", -1);
    else
        printf("%d\n",a->queuearr[a->front]);
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

int main()
{
 Queue queue;
 init(&queue);
 int n = 0;
 int num = 0;
 char s[10];

 scanf("%d", &n);

 for(int i = 0 ; i<n;i++)
 {
    scanf("%s",s);

    if(strcmp(s,"push") == 0)
    {
        scanf("%d", &num);
        push(&queue, num);

    }
    else if(strcmp(s,"pop") == 0)
    {
        pop(&queue);
    }
    else if(strcmp(s, "size") == 0)
    {
        Size(&queue);
    }
    else if(strcmp(s, "empty") == 0)
    {
        if(Is_Empty(&queue))
            printf("%d\n",1);
        else
            printf("%d\n",0);
    }
    else if(strcmp(s, "front") == 0)
    {
        Front(&queue);
    }
    else if(strcmp(s, "back") == 0)
    {
        Back(&queue);
    }
}
  free(queue.queuearr);
}

