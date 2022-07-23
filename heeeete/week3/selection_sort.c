/*	장점 - 자료 이동 횟수가 미리 결정된다.
	단점 - 안전성을 만족하지 않는다.
	- 즉, 값이 같은 레코드가 있는 경우에 상대적인 위치가 변경될 수 있다.   
	시간 복잡도 O(n^2)  */


void selection_sort(int N, int *arr)
{
    int small;
    for(int i = 0 ; i + 1 < N ; i++)
    {
        small = i;
        for(int j = i + 1 ; j < N ; j++)
        {
            if(arr[small] > arr[j])
            {
                small = j;
            }
        }
        int temp = arr[i];
        arr[i] = arr[small];
        arr[small] = temp;
    }
}