# 공간복잡도 : 주어진 배열이 차지하고 있는 공간 내에서 값들의 위치만 바꾸기 때문에 O(1)
# 시간복잡도 :
# 루프문을 통해 정렬 범위를 2개로 시작해서 전체로 확장해야 하기 때문에 기본적으로 O(N)을 시간을 소모,
# 각 패스에서는 정렬 범위에 새롭게 추가된 값과 기존 값들의 대소 비교 및 자리 교대를 위해서 O(N)을 시간이 필요
# 즉 O(N^2)의 시간 복잡도를 가지는 정렬 알고리즘

# 최적화를 통해서 부분적으로 정렬된 배열에 대해서 성능을 대폭 개선할 수 있으며, 
# 특히 완전히 정렬되어 있는 배열이 들어올 경우, O(N)까지도 시간 복잡도를 향상시킬 수 있음

def insertion_sort(arr):
    num = len(arr)
    for i in range (1, num):
        key = arr[i]
        for j in range (i - 1, -1, -1):  #i-1부터 0까지 역순으로
            if (key < arr[j]):
                arr[j + 1], arr[j] = arr[j], key
        
arr = [7, 5, 1, 4, 3]
print("original:", arr)
insertion_sort(arr)
print("insertion sort:", arr)