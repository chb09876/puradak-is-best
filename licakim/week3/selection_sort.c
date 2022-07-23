/*
선택 정렬 : 현재 레코드 뒤의 레코드 중 가장 작은 인덱스만 기억하여 현재 레코드와 교환하며 정렬
공간 복잡도:  θ(1)
-> 입력배열의 크기만이 사용되고 추가 저장장소 사용량이 없는 제자리 정렬
시간 복잡도: O(n^2)
-> 비교 횟수(내부루프) T(n) = (n-1)+(n-2)+...+1 = n(n-1)/2
   교환 횟수 (외부루프) T(n) = 3(n-1) n-1번 교환하며 3번의 저장(swap)이 필요 
*/

void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

void selection_sort(int n, int *arr)
{
    int i,j;
    int min;

    for(i = 0; i < n - 1; i++)
    {
        min = i;
        for(j = i + 1 ; j < n; j++)
        {
            if(arr[j] < arr[min])
            {
                min = j;
            }
        }
        swap(&arr[min],&arr[i]);
    }
}
