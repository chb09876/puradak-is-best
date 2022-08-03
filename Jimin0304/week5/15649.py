#N과 M

# map(적용할 함수, 순회 가능한 객체)
# 순회 가능한 객체의 각 원소에 지정한 함수를 각각 적용하여 결과를 반환하는 함수
# 공백으로 자른 input을 int 함수에 적용하여 결과 반환
N, M = map(int, input().split())

s = []

def dfs():
    # 1부터 N까지 자연수 중에 중복 없이 M개를 골랐을 때
    if (len(s) == M):
        print(' '.join(map(str, s))) # join함수를 이용해 각 수열을 공백으로 구분해서 출력

    for i in range (1, N + 1):
        if i in s:  # 중복 방지
            continue
        s.append(i)
        dfs()
        s.pop()  # 1 (dfs) -> 1 2 (출력) -> 1 (pop) -> 1 3 ...
            
dfs()
