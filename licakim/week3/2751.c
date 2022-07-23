#include<stdio.h>

int s[10000000];
int arr[10000000];

void merge(int start, int mid, int last)
{
    int i,j,k;
    i = start;
    j = mid + 1;
    k = start;
    while(i<=mid && j <= last)
    {
        if(arr[i] < arr[j])
        {
            s[k++] = arr[i++];
        }
        else
        {
            s[k++] = arr[j++];
        }
    }

    if(i > mid)
    {
        while(j<=last)
        {
            s[k++] = arr[j++];
        }
    }
    else
    {
        while(i<=mid)
        {
            s[k++] = arr[i++];
        }
    }
    for(int a = start; a <= last; a++)
    {
        arr[a] = s[a];
    }
}

void merge_sort(int start, int last)
{
    int mid;

    if(start < last)
    {
        mid = (start + last)/2;
        merge_sort(start, mid);
        merge_sort(mid+1, last);
        merge(start, mid, last);
    }
}

int main()
{
    int n = 0;
    int num = 0;
    scanf("%d", &n);
	
    for(int i = 0; i < n; i++)
    {
        scanf("%d",&arr[i]);
    }
	
    merge_sort(0,n-1);

	    
    for(int i = 0; i < n; i++)
    {
        printf("%d\n",arr[i]);
    }

}

