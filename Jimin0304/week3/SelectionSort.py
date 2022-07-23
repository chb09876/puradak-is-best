# 공간복잡도 : 주어진 배열이 차지하고 있는 공간 내에서 값들의 위치만 바꾸기 때문에 O(1)
# 시간복잡도 :
# 루프문을 통해 모든 인덱스에 접근해야 하기 때문에 기본적으로 O(N)을 시간을 소모,
# 하나의 루프에서는 현재 인덱스의 값과 다른 인덱스의 값들과 비교하여 최소값을 찾은 후 
# 현재 인덱스에 있는 값과 상호 자리 교대를(swap)해야 해야하기 때문에 O(N)을 시간이 필요
# 즉, O(N^2)의 시간 복잡도

def selection_sort(arr):
    num = len(arr)
    for i in range(0, num - 1):
        min_idx = i
        for j in range(i + 1, num):
            if arr[min_idx] > arr[j]:
                min_idx = j
        arr[i], arr[min_idx] = arr[min_idx], arr[i]

arr = [3, 5, 1, 4, 2]
print("original:", arr)
selection_sort(arr)
print("selection sort:", arr)