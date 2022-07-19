#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int age[201];
    char name[101];
}Person;

void init(Person *s)
{
    s->age = {0,};
}

int main()
{
    int N;
    scanf("%d", &N);
    Person p[N];
    for(int i = 0 ; i < N ; i++)
        scanf("%d%s", p)
}