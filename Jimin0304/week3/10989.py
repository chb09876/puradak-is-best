# 계수 정렬(counting sort)
# 배열에 존재하는 수의 개수를 세어주고, 이 정보를 바탕으로 정렬을 수행

import sys

num = int(input())

list = [0] * 10001  #원소의 최대값까지를 인덱스로 사용할 수 있도록 원소의 최대값 + 1

i = 0
while i < num:
    a = int(sys.stdin.readline())
    list[a] += 1    #list[a]는 숫자 a가 배열에 몇개 존재하는지에 대한 정보
    i += 1

for i in range(1, 10001):
    if list[i] != 0:
        for j in range(list[i]) :
             print(i)
             