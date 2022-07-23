#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int age;
    char name[101];
}Person;

/*    void selection_sort(Person *arr,int N) 선택정렬은 같은 값의 주소값이 바뀔수 있으므로 사용안함
{                                            그래서 삽입정렬을 사용
    int small;
    for(int i = 0 ; i + 1 < N ; i++)
    {
        small = i;
        for(int j = i + 1 ; j < N ; j++)
        {
            if(arr[small].age > arr[j].age)
            {
                small = j;
            }
        }
        Person temp = arr[i];
        arr[i] = arr[small];
        arr[small] = temp;
    }
}   */

/*    void insertion_sort(Person *arr, int N)   삽입정렬은 속도가 너무 오래 걸려서 시간초과
{
	Person key;
    int j;
	for(int i = 1 ; i < N ; i++)
	{
		key = arr[i];
		for(j = i - 1; j >= 0 && key.age < arr[j].age; j--) //J는 0보다 같거나 커야하며 key 값이 arr[j]보다 크면 반복문 종료
		{
			arr[j + 1] = arr[j];
		}
		arr[j + 1] = key;
	}
}   */

void merge(Person *arr, int low, int mid, int high, int N)
{
    Person temp[N];
    int i = 0;
    int j = low;
    int k = mid + 1;
    while(j <= mid && k <= high)     // 한쪽이 다 정렬 될때까지.
    {
        if(arr[j].age <= arr[k].age)         // 반으로 나눈값중 왼쪽 오른쪽 의 최솟값을 비교
        {
            temp[i] = arr[j];
            j++;
            i++;
        }
        else
        {
            temp[i] = arr[k];
            i++;
            k++;
        }
    }
    while(k <= high)                 // 왼쪽이 다 정렬되면 오른쪽의 남은값을 배열에 다넣음
    {
        temp[i] = arr[k];
        k++;
        i++;
    }
    while(j <= mid)                  // 오른쪽이 다 정렬되면 왼쪽의 남은값을 배열에 다넣음
    {
        temp[i] = arr[j];
        j++;
        i++;
    }
    i--;
    while(i >= 0)
    {
        arr[i + low] = temp[i];
        i--;
    }
}


void mergesort2(Person *arr, int low, int high, int N) //배열을 나누어 주는 함수
{
    if(low < high)
    {
        int mid = (low + high) / 2;
        mergesort2(arr, low, mid, N);
        mergesort2(arr, mid + 1, high, N);
        merge(arr, low, mid, high, N);
    }
    else
        return ;
}

int main()
{
    int N;
    scanf("%d", &N);
    Person p[N];
    for(int i = 0 ; i < N ; i++)
        scanf("%d%s", &p[i].age,p[i].name);
    mergesort2(p,0,N-1,N);
    for(int i = 0 ; i < N ; i++)
        printf("%d %s\n", p[i].age,p[i].name);
}