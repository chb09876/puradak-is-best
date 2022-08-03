#include <stdio.h>
#include <stdlib.h>

typedef struct Member
{
    char name[101];
    int age;
} Member;

int cmp(const void *a, const void *b)
{
    if (((Member *)a)->age > ((Member *)b)->age)
        return 1;
    else if (((Member *)a)->age < ((Member *)b)->age)
        return -1;
    else
        return 0;
}

Member mem_list[100000];

int main()
{
    int N;
    scanf("%d", &N);
    for (int i = 0; i < N; ++i)
        scanf("%d %s", &((mem_list + i)->age), (mem_list + i)->name);
    qsort(mem_list, N, sizeof(Member), cmp);
    for (int i = 0; i < N; ++i)
        printf("%d %s\n", (mem_list + i)->age, (mem_list + i)->name);
}