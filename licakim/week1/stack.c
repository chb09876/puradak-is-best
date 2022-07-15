#include<stdio.h>
#include<string.h>
#include<stdlib.h>

typedef struct
{
 int max_size;
 int *stackarr;
 int top;
} STACK;

void init(STACK *a)
{
    a->top = -1;
    a->max_size = 10;
    a->stackarr= (int *)malloc(sizeof(int) * a->max_size);
}

int Is_Empty(STACK *a)
{
	if(a -> top == -1)
        return 1;
	else
		return 0;
}

int Size(STACK *a)
{
    return (a->top + 1);
}

int Top(STACK *a)
{
	return(a->stackarr[a->top]); //top이 가리키는 자료 반환
}

int Pop(STACK *a)
{
	int temp = a->stackarr[a->top];
	a->top = a->top - 1;
	return temp;
}

void Push(STACK* a, int new_data)
{
	if(a->top + 1 == a->max_size)
	{
	   int *temp;	   
       temp = (int*)malloc(sizeof(int)* (a->max_size*2));
	   for(int k = 0; k < a->max_size; k++)
	      temp[k] = a ->stackarr[k];
	   a ->max_size = a -> max_size *2;
	   free(a -> stackarr);
	   a ->stackarr = temp;
    }
     a->top = a->top + 1;
     a->stackarr[a->top] = new_data;	  
}

