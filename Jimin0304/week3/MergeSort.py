# 공간 복잡도 : 두 개의 배열을 병합할 때 병합 결과를 담아 놓을 배열이 추가로 필요하기 때문에 O(N)
# 시간 복잡도 :
# 8 -> 4 -> 2 -> 1 식으로 전반적인 반복의 수는 점점 절반으로 줄어들 기 때문에 O(logN) 시간이 필요,
# 각 패스에서 병합할 때 모든 값들을 비교해야 하므로 O(N) 시간이 소모
# 즉, 시간 복잡도는 O(NlogN)

# 병합 정렬 알고리즘은 분할 정복(divide and conquer) 방식을 사용
# 분할(divide) -> 정복(conquer) -> 결합(combine)
# 정복의 단계에서는 각 부분 배열을 재귀적으로 병합 정렬을 이용해 정렬

def mergeSort(arr, left, right):
	if left >= right: return
	mid = (left + right) // 2
	mergeSort(arr, left, mid)
	mergeSort(arr, mid+ 1, right)
	merge(arr, left, mid + 1, right)


def merge(arr, left, right, end):
	temp = []
	l, r = left, right
	while l < right and r <= end:
		if arr[l] <= arr[r]:
			temp.append(arr[l])
			l +=1
		else:
			temp.append(arr[r])
			r +=1
	while l < right:
		temp.append(arr[l])
		l +=1
	while r <= end:
		temp.append(arr[r])
		r+=1

	l = left
	for n in temp:
		arr[l] = n	
		l +=1
            
            
arr = [6, 5, 3, 1, 8, 7, 2, 4]
print("original:", arr)
mergeSort(arr, 0, len(arr) - 1)
print("merge sort:", arr)