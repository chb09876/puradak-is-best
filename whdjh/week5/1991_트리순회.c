//0. 트리의 기본적인 단어 정리 1. 이진트리란? 2. 이진트리의 종류 3.이진트리의 표현 4. 이진트리의 순회
#include <stdio.h>
#include <stdlib.h>

typedef struct treenode {
    char data;
    struct treenode *left;
    struct treenode *right;
} treenode;

//트리 생성함수
treenode *init_tree(char alp)
{
    treenode *root = (treenode*)malloc(sizeof(treenode));
    root -> data = alp;
    root -> left = NULL;
    root -> right = NULL;
    return root;
}

//넣은 알파벳인가?
treenode *searching(treenode *root, char alp)
{
    if(root != NULL)
	{
        if(root -> data == alp)
            return root;
        else
		{
            treenode *n_root = searching(root -> left, alp);
            if(n_root != NULL) 	//왼쪽 뒤져봐!
                return n_root;
            else				//오른쪽 뒤져봐!
                return searching(root -> right, alp);
        }
    }
    else
        return NULL;
}

//넣어서 셋팅해볼까?
void setting(treenode *root, char a, char b, char c)
{
    root -> data = a;
    if (b != '.')
        root -> left = init_tree(b);
    if(c != '.')
        root -> right = init_tree(c);
}

//전위순회(VLR)
void preorder(treenode *root)
{
    if(root == NULL)
        return;
    else
	{
        printf("%c", root -> data);			//노드방문
        preorder(root -> left);				//왼쪽서브트리순회
        preorder(root -> right);			//오른쪽서브트리순회
    }
}

//중위순회(LVR)
void inorder(treenode *root)
{
    if(root == NULL)
        return;
    else
	{
    	inorder(root -> left);
        printf("%c", root -> data);
        inorder(root -> right);
    }
}

//후위순회(LRV)
void postorder(treenode *root)
{ 
    if(root == NULL)
        return;
    else
	{
        postorder(root -> left);
        postorder(root -> right);
        printf("%c", root -> data);
    }
}

int main() 
{
    int num;                            // 트리의 노드 갯수
    char a, b, c;                       // 노드와 왼쪽자식, 오른쪽 자식 노드
    treenode *tree = init_tree(NULL);   // 정답 도출용 작성되는 노드
    treenode *tmp; 				        // tree에서 나온 주소에 바로 이어서 작성하기 위한 노드

    scanf("%d", &num);
    getchar();
    for(int i = 0; i < num; i++)
	{
        scanf("%c %c %c", &a, &b, &c);
        getchar();
        tmp = searching(tree, a);
        if(tmp != NULL)
            setting(tmp, a, b, c);
        else
            setting(tree, a, b, c);
    }
    preorder(tree);
    printf("\n");
    inorder(tree); 
    printf("\n");
    postorder(tree);
    return 0;
}