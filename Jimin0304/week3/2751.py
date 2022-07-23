import sys

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
            
            
num = int(input())
i = 0
list = []
while i < num:
    list.append(int(sys.stdin.readline()))
    i += 1
mergeSort(list, 0, len(list) - 1)
for j in list:
    print(j)
    