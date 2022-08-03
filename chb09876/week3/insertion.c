#include <stdio.h>
void selection(int *arr, int size)
{
    for (int i = 1; i < size; ++i)
    {
        int key = arr[i];
        int j;
        for (j = i - 1; j >= 0 && arr[j] > key; --j)
        { // search extreme value
            arr[j + 1] = arr[j];
        }
        arr[j + 1] = key;
    }
}

int main()
{
    int arr[] = {9, 3, 2, 7, 6, -3};
    selection(arr, 6);
    for (int i = 0; i < 6; ++i)
    {
        printf("%d ", arr[i]);
    }
}