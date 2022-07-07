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
 	   printf("%d\n",a->stackarr[a->top]);
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

int main()
{
 int n = 0;
 char s[10];
 STACK stack; 
 
 init(&stack);

 scanf("%d", &n);

 for(int i = 0; i<n; i++)
 {
    scanf("%s",s);

    if(strcmp(s,"push") == 0)
    {
		int num;
        scanf("%d", &num);
        Push(&stack, num);

    }
    else if(strcmp(s,"pop") == 0)
    {
        Pop(&stack);
    }
    else if(strcmp(s, "top") == 0)
    {
        Top(&stack);
    }
    else if(strcmp(s, "size") == 0)
    {
        Size(&stack);
    }
    else if(strcmp(s, "empty") == 0)
    {
        if(Is_Empty(&stack))
		printf("%d\n", 1);
	else 
		printf("%d\n", 0);
    }

 }
 free(stack.stackarr);
}
