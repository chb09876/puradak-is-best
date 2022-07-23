/*
합병 정렬(분할정복) : 입력된 배열이 크기가 1이 될 때까지 재귀호출하며 분할 -> 정렬하며 합병
공간 복잡도:  θ(n)
-> 입력배열의 크기뿐만 아니라 추가적으로 입력배열 크기만큼의 임시 배열 필요
시간 복잡도: O(nlogn)
->  레코드의 개수를 계속 분할하니 호출을 log2n 하고 병합시 n만큼 비교 
*/

int arr[10000];
int s[10000];

void merge(int start, int mid, int last)
{
    int i,j,k;
    i = start;
    j = mid + 1;
    k = start;
    while(i<=mid && j<= last)
    {
        if(arr[i]<arr[j])
        {
            s[k] = arr[i];
            i++;
        }
        else
        {
            s[k] = arr[j];
            j++;
        }
        k++;
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
