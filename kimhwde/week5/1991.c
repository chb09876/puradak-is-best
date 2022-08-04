#include <stdio.h>

#include <stdlib.h>

 

// 구조체 세팅

typedef struct Node{

    char data;

    struct Node *left;

    struct Node *right;

}node;

 

// 노드 생성

node *makeNode(char ch){

    node *nd = (node*)malloc(sizeof(node));

    nd->data = ch;

    nd->left = NULL;

    nd->right = NULL;

    

    return nd;

}

 

// 이미 넣은 알파벳인지 확인 후 넣기

node *searchNode(node *nd, char ch){

    if(nd != NULL){

        if(nd->data == ch){

            return nd;

        }

        else{ // 왼쪽 뒤지고, 없으면 오른쪽 뒤짐

            node *ndd = searchNode(nd->left, ch);

            if(ndd != NULL){

                return ndd;

            }

            else

                return searchNode(nd->right, ch);

        }

    }

    else

        return NULL;

}

 

// 노드에 값 집어넣기

void setNode(node *nd, char fir, char sec, char thr){

    nd->data = fir;

    if (sec != '.'){

        nd->left = makeNode(sec);

    }

    if(thr != '.'){

        nd->right = makeNode(thr);

    }

}

 

// 전위 순회 출력

void preorderPrint(node *nd){

    if(nd == NULL){

        return;

    }

    else{

        printf("%c", nd->data);

        preorderPrint(nd->left);

        preorderPrint(nd->right);

    }

}

 

 // 중위 순회 출력

void inorderPrint(node *nd){

    if(nd == NULL){

        return;

    }

    else{

        inorderPrint(nd->left);

        printf("%c", nd->data);

        inorderPrint(nd->right);

    }

}

 

// 후위 순회 출력

void postorderPrint(node *nd){ 

    if(nd == NULL){

        return;

    }

    else{

        postorderPrint(nd->left);

        postorderPrint(nd->right);

        printf("%c", nd->data);

    }

}

 

int main() {

    int num; // 트리의 노드 갯수

    char a, b, c; // 노드와 왼쪽자식, 오른쪽 자식 노드

    

    node *tree = makeNode(NULL); // 정답 도출용 작성되는 노드

    node *tree2; // tree에서 나온 주소에 바로 이어서 작성하기 위한 노드

    

    scanf("%d", &num);

    getchar();

    

    // num만큼 for문을 통해 값 입력받고, node에 추가

    for(int i = 0; i < num; i++){

        scanf("%c %c %c", &a, &b, &c);

        getchar();

        

        tree2 = searchNode(tree, a);

        

        if(tree2 != NULL){ // tree노드에 있는 값이라는 뜻 => tree노드에서 a가 들어갈 주소를 갖고있는 tree2에 넣기

            setNode(tree2, a, b, c);

        }

        else{ // 처음에 A를 집어넣는 과정

            setNode(tree, a, b, c);

        }

    }

    

    // 전위, 중위, 후위에 맞게 출력

    preorderPrint(tree); 

    printf("\n");

    inorderPrint(tree); 

    printf("\n");

    postorderPrint(tree); 

    return 0;

}