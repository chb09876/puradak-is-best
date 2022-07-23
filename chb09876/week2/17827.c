#include <stdio.h>

int main()
{
    int N, M, N_next;
    scanf("%d %d %d", &N, &M, &N_next);
    int cycle_length = N - N_next + 1;

    // make list
    int list[200000];
    for (int i = 0; i < N; ++i)
    {
        int value;
        scanf("%d", &value);
        list[i] = value;
    }

    for (int i = 0; i < M; ++i)
    {
        int K;
        scanf("%d", &K);
        if (K > N - 1)
            printf("%d\n", list[(K - (N - cycle_length)) % cycle_length + (N - cycle_length)]);
        else
            printf("%d\n", list[K]);
    }
}
