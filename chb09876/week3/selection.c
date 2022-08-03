#include <stdio.h>

void swap(int *a, int *b)
{
    int tmp = *a;
    *a = *b;
    *b = tmp;
}

void insertion(int *arr, int size)
{
    for (int i = 0; i < size - 1; ++i)
    {
        int extreme_idx = i;
        for (int j = i; j < size; ++j)
        { // search extreme value
            if (arr[extreme_idx] < arr[j])
                extreme_idx = j;
        }
        swap(&arr[i], &arr[extreme_idx]);
    }
}

int main()
{
    int arr[] = {9, 3, 2, 7, 6, -3};
    insertion(arr, 6);
    for (int i = 0; i < 6; ++i)
    {
        printf("%d ", arr[i]);
    }
}