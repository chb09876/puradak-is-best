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
		if arr[l][0] <= arr[r][0]:
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

import sys

num = int(input())
member = []

i = 0
while i < num:
    age, name = sys.stdin.readline().split()
    age = int(age)
    member.append([age, name])
    i += 1
    
mergeSort(member, 0, num - 1)

for i in range(num):
    print(member[i][0], member[i][1])
    