#include <stdio.h>
#include <stdlib.h>

void merge_sort(int *arr, int *temp, int size);
// int arr[1000000], temp[1000000]; // 메모리 영역에 따라 변수의 최대 사이즈가 다르다. 전역변수는 data영역, 함수 안에서는 stack 영역에 저장됨.

int main()
{
    int N;
    scanf("%d", &N);
    int *arr = malloc(sizeof(int) * N);
    int *temp = malloc(sizeof(int) * N);

    for (int i = 0; i < N; ++i)
        scanf("%d", arr + i);
    merge_sort(arr, temp, N);
    for (int i = 0; i < N; ++i)
        printf("%d\n", arr[i]);
}

void merge_sort(int *arr, int *temp, int size)
{
    for (int window = 1; window < size; window *= 2)
    {
        for (int left = 0; left + window < size; left += 2 * window)
        {
            int right = left + window;
            int end = right + window;
            if (end > size)
                end = size;

            int k = left;
            int l = left;
            int r = right;
            while (l < right && r < end)
            {
                if (arr[l] > arr[r])
                    temp[k++] = arr[r++];
                else
                    temp[k++] = arr[l++];
            }
            while (l < right)
                temp[k++] = arr[l++];
            while (r < end)
                temp[k++] = arr[r++];
            for (k = left; k < end; ++k)
                arr[k] = temp[k];
        }
    }
}