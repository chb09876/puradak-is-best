#include <stdlib.h>
#include "list.h"

List *create_list()
{
	List *list = (List *)malloc(sizeof(List));
	list->head = 0;
	list->size = 0;
	return list;
}

void append(List *list, int value)
{
	if (size(list) == 0)
		list->head = create_node(value);
	else
	{
		Node *node = list->head;
		
		while (get_next(node))
			node = get_next(node);
		
		set_next(node, create_node(value));
	}
	++list->size;
}

Node *get_nth_node(List *list, int nth)
{
	if (list->size < nth)
		return 0;
	Node *node = list->head;
	while (--nth)
		node = get_next(node);
	return node;
}

void set_nth_node(List *list, int value, int nth)
{
	if (nth == 1)
	{
		Node *node = create_node(value);
		set_next(node, list->head);
		list->head = node;
		++list->size;
	}
	else if (list->size < nth)
		return;
	else
	{
		Node *dest = create_node(value);
		Node *node = get_nth_node(list, nth - 1);
		Node *next = get_next(node);
		set_next(node, dest);
		set_next(dest, next);
		++list->size;
	}
}

int find(List *list, int value)
{
	Node *node = list->head;
	int nth = 0;
	while (node)
	{
		++nth;
		if (get_value(node) == value)
			return nth;
	}
	return 0;
}

void remove_by_value(List *list, int value)
{
	Node *node = list->head;
	Node *prev = 0;
	while (node)
	{
		if (get_value(node) == value)
		{
			--list->size;
			if (prev == 0)
			{
				Node *tmp = node;
				node = get_next(node);
				delete_node(tmp);
			}
			else
			{
				node = get_next(node);
				delete_node(get_next(prev));
				set_next(prev, node);
			}
		}
		else
		{
			prev = node;
			node = get_next(node);
		}
	}

}

int empty(List *list)
{
	return list->size == 0;
}

int size(List *list)
{
	return list->size;
}

void delete_list(List *list)
{
	while (list->head)
	{
		Node *tmp = list->head;
		list->head = get_next(tmp);
		delete_node(tmp);
	}
}