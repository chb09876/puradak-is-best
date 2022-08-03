# 체스판 다시 칠하기

N, M = map(int, input().split())

board = []
cnt = []

for _ in range (N):
    board.append(input())

# 보드판을 8X8 체스로 자르는 경우 (EX. 10X13 보드판이면 가로 3번, 세로 6번)
for i in range (N - 7):
    for j in range (M - 7):
        W_start = 0 # W로 시작했을 때 다시 칠하는 횟수
        B_start = 0 # B로 시작했을 때 다시 칠하는 횟수
        
        # 잘라진 체스판 색깔 검사
        for k in range (i, i + 8):
            for l in range (j, j + 8):
                
                # 첫번째 칸이랑 같은 색
                if (k + l) % 2 == 0:
                    if board[k][l] != 'W':  # W로 시작했는데 첫번째 칸이 W가 아니면 칠해야 함
                        W_start += 1
                    if board[k][l] != 'B':  # B로 시작했는데 첫번째 칸이 B가 아니면 칠해야 함
                        B_start += 1
                        
                # 첫번쨰 칸이랑 다른 색
                else:
                    if board[k][l] != 'B':  # W로 시작했는데 두번째 칸이 B가 아니면 칠해야 함
                        W_start += 1
                    if board[k][l] != 'W':  # B로 시작했는데 두번째 칸이 W가 아니면 칠해야 함
                        B_start += 1
        
        # 한 번의 체스판 다시 칠하기가 끝났을 때 횟수 저장
        cnt.append(W_start)
        cnt.append(B_start)
        
print(min(cnt))    
