# 일곱 난쟁이

height = []
for _ in range(9):
    height.append(int(input()))

height.sort() #난쟁이 키 미리 정렬

for i in range(0, 8):
    for j in range(i + 1, 9):
        # 9명 키의 합에서 특정 2명의 키를 뺐을 때 100이 되는 경우
        if (sum(height) - (height[i] + height[j])) == 100:
            for k in range(9):
                if (k != i and k != j):  #삭제 될 난쟁이 빼고 출력
                    print(height[k])
            exit()
            #exit 안했을 때 틀림.. 왜?
            #런타임에러도 아니고 틀렸습니다