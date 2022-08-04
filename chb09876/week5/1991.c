#include <stdio.h>
#include <stdlib.h>

typedef struct Pair
{
    char first;
    char second;
} Pair;

void preorder_traversal(Pair *arr, char name);

int main()
{
    Pair arr[26];
    int N;
    scanf("%d", &N);
    for (int i = 0; i < N; ++i)
    {
        // char p, l, r;
        // scanf("%c %c %c ", &p, &l, &r);
        // arr[p - 'A'].first = l;
        // arr[p - 'A'].second = r;
    }
    // preorder_traversal(arr, 'A');
}

void preorder_traversal(Pair *arr, char name)
{
    printf("%c", name);
    if (arr->first != '.')
        preorder_traversal(&arr[arr->first - 'A'], arr->first);
    if (arr->second != '.')
        preorder_traversal(&arr[arr->second - 'A'], arr->second);
}
void inorder_traversal(Pair *arr);
void postorder_traversal(Pair *arr);