typedef struct Node 
{
	struct Node *next;
	int value;
} Node;

Node *create_node(int value);
Node *get_next(Node *node);
void set_next(Node *node, Node *next);
int get_value(Node *node);
void set_value(Node *node, int value);
void delete_node(Node *node);