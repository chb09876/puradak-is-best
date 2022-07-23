/*	시간복잡도 - O(n^2)
	공간복잡도 - O(1)
	선택정렬, 버블정렬에 비해 상대적으로 빠름	*/

#include <stdio.h>

void insertion_sort(int arr[], int N)
{
	int key, j;
	for(int i = 1 ; i < N ; i++)
	{
		key = arr[i];
		for(j = i - 1; j >= 0 && key < arr[j]; j--) //J는 0보다 같거나 커야하며 key 값이 arr[j]보다 크면 반복문 종료
		{
			arr[j + 1] = arr[j];
		}
		arr[j + 1] = key;
	}
}


/*	int main()
{
		int arr[] = {5,1,2,2,1,6,7,4,6,78};
		insertion_sort(arr, sizeof(arr) / sizeof(int));
		for(int i = 0 ; i < sizeof(arr) / sizeof(int) ; i++)
			printf("%d\n", arr[i]);	
}	*/