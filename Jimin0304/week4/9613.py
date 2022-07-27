import sys

def gcd(a, b):
    for i in range(min(a, b), 0, -1):
        if (a % i == 0 and b % i == 0):
             return (i)

T = int(input())
for i in range(0, T):
    arr = list(map(int, sys.stdin.readline().split()))
    result = 0
    for j in range(1, len(arr)):
        for k in range(j + 1, len(arr)):
            result += gcd(arr[j], arr[k])
    print(result)