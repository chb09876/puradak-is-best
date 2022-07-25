#include <stdio.h>

typedef struct {
    int age;
    char name[201];
} member;
   
member  list[100001];

int main()
{
    int num;

    scanf("%d", &num);
    for(int i = 0; i < num; i++)        //회원의 수까지 나이와 이름을 입력받음
        scanf("%d %s", &list[i].age, list[i].name);
    for(int i = 1; i <= 200; i++)       //i = 1인 이유는 나이가 1살부터이므로
    {
        for (int j = 0; j < num; j++)
        {
            if (i == list[j].age)
                printf("%d %s\n", list[j].age, list[j].name);
        }
    }
}
