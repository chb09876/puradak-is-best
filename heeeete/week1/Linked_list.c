#include <stdio.h>
#include <stdlib.h>

typedef struct node{
	int data;
	struct node *next;
}node;

node *createnode(int data)
{
	node *newnode = (node *)malloc(sizeof(node));

	newnode->data = data;
	newnode->next = NULL;
	
	return newnode;
}

node *addfirst(node *head, int data)
{
	node *newnode = (node *)malloc(sizeof(node));

	newnode->data = data;
	newnode->next = head;

	return newnode;
}

node *insertnode(node *current, int data)
{
	node *newnode = (node *)malloc(sizeof(node));
	newnode->data = data;
	newnode->next = current->next;
	current->next = newnode;

	return newnode;
}

void printnode(node *head)
{
	while (head)
	{
		printf("%d\n", head->data);
		head = head->next;
	}
}

void nodemodify(node *NODE, int data)
{
	NODE->data = data;
}

int main()
{
	node *node1 = createnode(200);
	node *node0 = addfirst(node1,100);
	nodemodify(node0,1000);
	node *node2 = insertnode(node1,300);
	node *node3 = insertnode(node1,400);
	printnode(node0);
}