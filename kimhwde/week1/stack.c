typedef struct list_node* list_pointer; // list노드의 주소를 저장할 포인터를 선언함
typedef struct list_node {
	int data; //데이터가 들어감
	list_pointer link; //다음 노드의 주소를 저장할 포인터
};

/**삽입
a->b->c(빈데이터) 이렇게 스택이 배치되어있으면
c의 자리에 삽입을 하고 c의 주소를 구조체의 멤버인 link에 넣어놓는다.
**/

void push(list_pointer stack, int item) {
	list_pointer temp;
	temp = (list_pointer)malloc(sizeof(list_node));
	if (temp == NULL) { //동적으로 구조체를 선언했을 때 메모리확보가 불가능하면 null을 반환함
		printf("스택이 다 찼습니다.");
		return;
	}
	temp->data = 10;
	temp->link = stack->link;
	stack->link = temp;	
}

//삭제
 void pop(list_pointer stack)
{
	list_pointer temp;
	int item;
	if (stack->link == NULL) { //마지막 삽입한 노드의 다음 노드의 포인터는 null을 가르키고있다
		printf("스택이 비었습니다.");
		return;
	}
	temp = stack->link;//마지막 삽입한 원소의 
	item = temp->data;//뺀거는 item 에 담아놓고
	stack->link = temp->link;//마지막 전에 노드는 제일 마지막 노드가 가르키고 있던 다음 노드의 주소를 다시 받아간다.
	free(temp);

}


