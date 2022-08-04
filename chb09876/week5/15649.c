#include <stdbool.h>
#include <stdio.h>

void select(bool *is_selected, int *stack, int N, int M);

int main()
{
    bool is_selected[8] = {
        0,
    };
    int stack[8] = {
        0,
    };

    int N, M;
    scanf("%d %d", &N, &M);
    for (int i = 0; i < N; ++i)
    {
        stack[0] = i + 1;
        is_selected[i] = true;
        select(is_selected, stack, N, M);
        stack[0] = 0;
        is_selected[i] = false;
    }
}

void select(bool *is_selected, int *stack, int N, int M)
{
    static int level = 0;
    if (level == M - 1)
    {
        printf("%d", stack[0]);
        for (int i = 1; i < M; ++i)
            printf(" %d", stack[i]);
        printf("\n");
        return;
    }
    for (int i = 0; i < N; ++i)
    {
        if (is_selected[i] == false)
        {
            stack[++level] = i + 1;
            is_selected[i] = true;
            select(is_selected, stack, N, M);
            stack[level--] = 0;
            is_selected[i] = false;
        }
    }
}