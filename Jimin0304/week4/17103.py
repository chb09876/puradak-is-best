#에라토스테네스의 체 (소수가 아닌 것에는 0)
arr = [0] * (1000001)
    
for i in range (2, 1000001):
    arr[i] = i

for i in range (2, 1000001):
    if arr[i] != 0:
        for j in range(i * i, 1000001, i):
            arr[j] = 0
    
#골드바흐 파티션
T = int(input())
for i in range (0, T):
    N = int(input())
    
    res = 0    
    for i in range (2, N // 2 + 1):
        if arr[i] and arr[N-i]:
            res += 1
    print(res)
