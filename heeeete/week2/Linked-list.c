#include <stdio.h>
#include <stdlib.h>

typedef struct node{
	int data;
	struct node *next;
}node;

node *CreateNode(int data)
{
	node *newnode = (node *)malloc(sizeof(node));

	newnode->data = data;
	newnode->next = NULL;
	
	return newnode;
}

node *AddFirstNode(node *head, int data)
{
	node *newnode = (node *)malloc(sizeof(node));

	newnode->data = data;
	newnode->next = head;

	return newnode;
}

node *Insertnode(node *current, int data)
{
	node *newnode = (node *)malloc(sizeof(node));
	newnode->data = data;
	newnode->next = current->next;
	current->next = newnode;

	return newnode;
}

void PrintNode(node *head)
{
	while (head)
	{
		printf("%d\n", head->data);
		head = head->next;
	}
}

void NodeModify(node *NODE, int data)
{
	NODE->data = data;
}

char *Search(node *head, int data)
{
	while(head)
	{
		if(head->data == data)
		{
			return "TRUE\n";
		}
		head = head->next;
	}
	return "FALSE\n";
}

void DeleteNode(node *NODE, node *head)
{
	if(NODE == head)
	{
		free(NODE);
		return ;
	}
	while(head)
	{
		if(head->next == NODE)
		{
			head->next = NODE->next;
		}
		head = head->next;
	}
	free(NODE);
}

int main()
{
	node *node1 = CreateNode(200);
	node *node0 = AddFirstNode(node1,100);
	NodeModify(node0,1000);
	node *node2 = InsertNode(node1,300);
	node *node3 = InsertNode(node1,400);
	DeleteNode(node3, node0);
	PrintNode(node0);
	printf("%s", search(node0, 1000));
}