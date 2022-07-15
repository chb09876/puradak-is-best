#include <stdlib.h>
#include "node.h"

Node *create_node(int value)
{
	Node *node = (Node *)malloc(sizeof(Node));
	node->next = 0;
	node->value = value;
	return node;
}

Node *get_next(Node *node)
{
	return node->next;
}

void set_next(Node *node, Node *next)
{
	node->next = next;
}

int get_value(Node *node)
{
	return node->value;
}

void set_value(Node *node, int value)
{
	node->value = value;
}

void delete_node(Node *node)
{
	free(node);
}