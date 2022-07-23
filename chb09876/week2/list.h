#include "node.h"

typedef struct List 
{
	Node *head;
	int size;
} List;

List *create_list();
void append(List *list, int value);
Node *get_nth_node(List *list, int nth);
void set_nth_node(List *list, int value, int nth);
int find(List *list, int value);
void remove_by_value(List *list, int value);
int empty(List *list);
int size(List *list);
void delete_list(List *list);