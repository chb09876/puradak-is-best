#include<stdio.h>
#include<string.h>

typedef struct
{
 char name[101];
 int age;
} member;

member m[100000];
member m2[100000];

void merge(int start, int mid, int last)
{
    int i,j,k;
    i = start;
    j = mid + 1;
    k = start;
    while(i<=mid && j <= last)
    {
        if(m[i].age <= m[j].age)
        {
            m2[k++] = m[i++];
        }
        else
        {
            m2[k++] = m[j++];
        }
    }

    while(j <= last)
    {
         m2[k++] = m[j++];
    }

    while(i <= mid)
    {
        m2[k++] = m[i++];
    }

    for(int a = start; a <= last; a++)
    {
        m[a] = m2[a];
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
    char c[101];
    int n,num;
    scanf("%d",&n);

    for(int k = 0; k < n; k++)
    {
        scanf("%d",&m[k].age);
        scanf("%s",m[k].name);
    }

    merge_sort(0,n-1);
    
    for(int k=0; k < n; k++)
    {
        printf("%d %s\n",m[k].age, m[k].name);
    }
}
