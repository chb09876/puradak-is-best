/*  시간복잡도 - O(nlogn)
    장점 - 안정적인 정렬법
        - 빠름
    단점 - 구현이 어려움    */

void merge(int arr[], int low, int mid, int high, int N)
{
    int temp[N];
    int i = 0;
    int j = low;
    int k = mid + 1;
    while(j <= mid && k <= high)     // 한쪽이 다 정렬 될때까지.
    {
        if(arr[j] <= arr[k])         // 반으로 나눈값중 왼쪽 오른쪽 의 최솟값을 비교
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

void mergesort(int arr[], int low, int high, int N) //배열을 나누어 주는 함수
{
    if(low < high)
    {
        int mid = (low + high) / 2;
        mergesort(arr, low, mid, N);
        mergesort(arr, mid + 1, high, N);
        merge(arr, low, mid, high, N);
    }
    else
        return ;
}
