//0. 트리의 기본적인 단어 정리 1. 이진트리란? 2. 이진트리의 종류 3.이진트리의 표현 4. 이진트리의 순회
#include <stdio.h>
#include <stdlib.h>

typedef struct treenode {
	char data;
	struct treenode *left;
	struct treenode *right;	
} treenode;

//노드 생성함수
treenode *init_node(char alp)
{
	treenode *root = (treenode *)malloc(sizeof(treenode));
	root -> data = alp;
	root -> left = NULL;
	root -> right = NULL;
	return root;
}

//넣은 알파벳인가?
treenode *search(treenode *root, char alp)
{
	if(root != NULL)
	{
		if(root -> data == alp)
			return root;
	
		else //왼쪽 없으면 오른쪽
		{
			treenode *newroot = search(root -> left, alp);
			if(newroot != NULL)
				return newroot;
			else
				return search(root -> right, alp);
		}
	}
	else
		return NULL;
}

//값을 집어넣자
void setting(treenode *root, char first, char second, char third)
{
	root -> data = first;
	if(second != '.')
		root -> left = init_node(second);
	if(third != '.')
		root -> right = init_node(third);
}

//전위순회(VLR)
void preorder(treenode *root)
{
	if(root == NULL)
		return;
	else 
	{
		printf("%c", root -> data);			//노드 방문
		preorder(root -> left);				//왼쪽서브트리 순회
		preorder(root -> right);			//오른쪽서브트리 순회
	}
}

//중위순회(LVR)
void inorder(treenode *root)
{
	if(root == NULL)
		return;
	else
	{
		inorder(root -> left);				//왼쪽서브트리 순회
		printf("%c", root -> data);			//노드 방문
		inorder(root -> right);				//오른쪽서브트리 순회
	}
}

//후위순회(LRV)
void postorder(treenode *root)
{
	if(root == NULL)
		return;
	else
	{
		postorder(root -> left);			//왼쪽서브트리 순회
		postorder(root -> right);			//오른쪽서브트리 순회
		printf("%c ", root -> data);		//노드 방문
	}
}

int main() {

    int num; // 트리의 노드 갯수

    char a, b, c; // 노드와 왼쪽자식, 오른쪽 자식 노드

    

    treenode *tree = init_node(NULL); // 정답 도출용 작성되는 노드

    treenode *tree2; // tree에서 나온 주소에 바로 이어서 작성하기 위한 노드

    

    scanf("%d", &num);

    getchar();

    

    // num만큼 for문을 통해 값 입력받고, node에 추가

    for(int i = 0; i < num; i++){

        scanf("%c %c %c", &a, &b, &c);

        getchar();

        

        tree2 = search(tree, a);

        

        if(tree2 != NULL){ // tree노드에 있는 값이라는 뜻 => tree노드에서 a가 들어갈 주소를 갖고있는 tree2에 넣기

            setting(tree2, a, b, c);

        }

        else{ // 처음에 A를 집어넣는 과정

            setting(tree, a, b, c);

        }

    }

    

    // 전위, 중위, 후위에 맞게 출력

    preorder(tree); // 전위

    printf("\n");

    inorder(tree); // 중위

    printf("\n");

    postorder(tree); // 후위

    return 0;
}