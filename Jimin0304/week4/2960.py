#에라토스테네스의 체

import sys

N, K = sys.stdin.readline().split()
N = int(N)
K = int(K)

primeNum = [0] * (N + 1)

#배열 초기화
for i in range (2, N + 1):
    primeNum[i] = i

count = 0
for i in range (2, N + 1):
    for j in range(i, N + 1, i):
        if (primeNum[j] != 0):
            primeNum[j] = 0
            count += 1
            if (count == K):
                print(j)
