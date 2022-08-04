#include<stdio.h>

void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

void selection_sort(int n, int *arr)
{
    int i,j;
    int min;

    for(i = 0; i < n - 1; i++)
    {
        min = i;
        for(j = i + 1 ; j < n; j++)
        {
            if(arr[j] < arr[min])
            {
                min = j;
            }
        }
        swap(&arr[min],&arr[i]);
    }
}


int main()
{
    int arr[9];
    int sum = 0;
    for( int i = 0; i<9; i++)
    {
        scanf("%d",&arr[i]);
        sum += arr[i];
    }
	
    selection_sort(9, arr);
    int find = sum - 100;
    int i, j;
    for(i=0; i<8; i++)
    {
        for(j =1; j<9; j++)
        {
            if(arr[i]+arr[j]==find)
            {
		break;
            }
        }
	if(arr[i]+arr[j] ==find)
		break;
    }

    for(int k=0; k<9; k++)
    {
	if(k != i && k != j)
		printf("%d\n",arr[k]);
    } 
}
