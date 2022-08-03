#트리 순회

N = int(input())

#딕셔너리 : 키와 값을 한 쌍을 이루게 함 (키를 이용해 값에 접근)
tree = {}
for _ in range(N):
    root, left,right = input().split()
    tree[root] = [left, right]   #root가 키 / left, right가 값
    
#전위 순회 (루트)(왼쪽 자식)(오른쪽 자식)
def preorder(root):
    if root != '.':
        print(root, end = '') #end 옵션을 사용하여 뒤의 출력값과 이어서 출력 (줄바꿈 x)
        preorder(tree[root][0])  #이중 딕셔너리 (left 부터)
        preorder(tree[root][1])

#중위 순회 (왼쪽 자식)(루트)(오른쪽 자식)
def inorder(root):
    if root != '.':
        inorder(tree[root][0])
        print(root, end = '')
        inorder(tree[root][1])
        
#후위 순회 (왼쪽 자식)(오른쪽 자식)(루트)
def postorder(root):
    if root != '.':
        postorder(tree[root][0])
        postorder(tree[root][1])
        print(root, end = '')
        
preorder('A')
print()  #개행 -> print는 기본적으로 출력하는 값 끝에 \n을 붙임
inorder('A')
print()
postorder('A')
        
        