/*
삽입 정렬:이미 정렬된 배열에 레코드를 삽입하여 정렬하는 알고리즘
공간 복잡도:  θ(1)
-> 입력배열의 크기만이 사용되고 추가 저장장소 사용량이 없는 제자리 정렬
시간 복잡도: O(n^2)
-> 최악 : 배열이 역으로 정렬되어 있는 경우로 주어진 i에 대해 i-1번씩 W(n)=n(n-1)/2 
   최적 : 배열이 정렬되어 있는 경우 주어진 i에 대해 한번씩만 비교 n
*/
#include<stdio.h>

void insertion_sort(int n, int *arr)
{
    int i,j;
    int temp;

    for(i =1; i<n; i++)
    {
        temp = arr[i];
        j = i -1;
        while(j >= 0 && arr[j] > temp)
        {
            arr[j+1] = arr[j];
            j--;            
        }
	arr[j+1] = temp;
    }
}
