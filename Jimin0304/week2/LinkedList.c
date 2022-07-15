#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* nextNode;
};

//CreateNode
struct Node* CreateNode(int data) {
    struct Node* newNode;
    newNode = (struct Node*)malloc(sizeof(struct Node));

    newNode->data = data;
    newNode->nextNode = NULL;

    return newNode;
}

//InsertNode
struct Node* InsertNode(struct Node* current, int data) {
    struct Node* after = current->nextNode;
    struct Node* newNode;
    newNode = (struct Node*)malloc(sizeof(struct Node));

    newNode->data = data;
    newNode->nextNode = after;
    current->nextNode = newNode;

    return newNode;
}

//DeleteNode
void DestroyNode(struct Node* destroy, struct Node* head) {   //head는 맨 처음 노드
    struct Node* next = head;
    if (destroy == head) {     //head를 파괴할 때
        free(destroy);
        return ;
    }

    while (next) {    //next가 NULL이기 전까지
        if (next->nextNode == destroy)
            next->nextNode = destroy->nextNode;    //바로 free를 해버리면 메모리가 파괴되는 것이기 때문에
        next = next->nextNode;                     //nextNode를 바꾸고 free선언
    }                            
    free(destroy);
    return ;
}


//SearchNode
struct Node* SearchNode(struct Node* head, int data) {
   struct Node* current = head;

    while(current) {
        if (current->data == data)
            return current;
        current = current->nextNode;
    }
    return NULL;
}

int main() {
    struct Node* Node1 = CreateNode(100);
    struct Node* Node2 = InsertNode(Node1, 200);
    struct Node* Node3 = InsertNode(Node2, 300);
    struct Node* Node4 = InsertNode(Node2, 400);
    struct Node* Node5 = SearchNode(Node1, 300);
    DestroyNode(Node2, Node1);

    while (Node1) {
        printf("Node Data : %d\n", Node1->data);
        Node1 = Node1->nextNode;
    }
    printf("Search Node Address : 0x%p / Search Node Data : %d\n", Node5, Node5->data);
}