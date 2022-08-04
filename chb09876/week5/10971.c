#include <stdio.h>
#include <stdbool.h>

int MATRIX[10][10];
int VISITED[10] = {
    0,
};
int MIN_COST = __INT_MAX__;
int COST = 0;

void visit(int from, int to, int cycle, int N);
bool is_visit_all(int N);

int main()
{
    int N;
    scanf("%d", &N);
    for (int i = 0; i < N; ++i)
    {
        for (int j = 0; j < N; ++j)
            scanf("%d", &MATRIX[i][j]);
    }

    for (int i = 0; i < N; ++i)
    {
        VISITED[i] = true;
        for (int j = 0; j < N; ++j)
        {
            if (MATRIX[i][j])
                visit(i, j, i, N);
        }
        VISITED[i] = false;
    }

    printf("%d", MIN_COST);
}

void visit(int from, int to, int cycle, int N)
{
    static int cost = 0;
    // do side effect //
    cost += MATRIX[from][to];
    VISITED[to] = true;
    ////////////////////
    if (is_visit_all(N) && MATRIX[to][cycle])
    {
        if (MIN_COST > cost + MATRIX[to][cycle])
            MIN_COST = cost + MATRIX[to][cycle];
    }
    else
    {
        for (int i = 0; i < N; ++i)
        {
            if (VISITED[i] == false && MATRIX[to][i])
                visit(to, i, cycle, N);
        }
    }
    // undo //////////////
    cost -= MATRIX[from][to];
    VISITED[to] = false;
    //////////////////////
}

bool is_visit_all(int N)
{
    for (int i = 0; i < N; ++i)
    {
        if (VISITED[i] == false)
            return false;
    }
    return true;
}