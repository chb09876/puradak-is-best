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
<<<<<<< HEAD
	if(a -> top == -1)
        return 1;
	else
		return 0;
=======
   if(a -> top == -1)
        return 1;
   else
	return 0;
>>>>>>> 41dcd070ceee5a5b2fe82fd1950865e8269f6fb0
}

int Size(STACK *a)
{
    return (a->top + 1);
}

int Top(STACK *a)
{
<<<<<<< HEAD
	return(a->stackarr[a->top]); //top이 가리키는 자료 반환
=======
    if(Is_Empty(a))
	   printf("%d\n",-1);
    else
 	   printf("%d\n",a->stackarr[a->top]); //top이 가리키는 자료 출력
>>>>>>> 41dcd070ceee5a5b2fe82fd1950865e8269f6fb0
}

int Pop(STACK *a)
{
<<<<<<< HEAD
	int temp = a->stackarr[a->top];
	a->top = a->top - 1;
	return temp;
=======
    if(Is_Empty(a))
	   printf("%d\n", -1);
    else
    {
	   Top(a);
	   a->top = a->top - 1;
     }
>>>>>>> 41dcd070ceee5a5b2fe82fd1950865e8269f6fb0
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
<<<<<<< HEAD
     a->top = a->top + 1;
     a->stackarr[a->top] = new_data;	  
=======
    a->top = a->top + 1;
    a->stackarr[a->top] = new_data;	  
>>>>>>> 41dcd070ceee5a5b2fe82fd1950865e8269f6fb0
}

