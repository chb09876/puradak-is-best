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

void Size(STACK *a)
{
    printf("%d\n",a->top + 1);
}

void Top(STACK *a)
{
    if(Is_Empty(a))
	   printf("%d\n",-1);
    else
 	   printf("%d\n",a->stackarr[a->top]); //top이 가리키는 자료 출력
}

void Pop(STACK *a)
{
    if(Is_Empty(a))
	   printf("%d\n", -1);
    else
    {
	   Top(a);
	   a->top = a->top - 1;
     }
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
