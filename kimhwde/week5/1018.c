#include <stdio.h>

#define minFinder(a, b) a < b ? a : b

int main()
{
    int a, b, i, j;
    char arr[51][51];
    int n, m, flagW, flagB, min = 80;
    scanf("%d %d", &n, &m);
    i = 0;
    while (i < n)
    {
        scanf("%s", &arr[i]);
        i++;
    }
    i = 0;
    while (i + 7 < n)
    {
        j = 0;
        while (j + 7 < m)
        {
            flagW = 0;
            flagB = 0;
            a = i;
            while (a < i + 8)
            {
                b = j;
                while (b < j + 8)
                {
                    if ((a + b) % 2 == 0)
                    {
                        if (arr[a][b] == 'B')
                            flagW++;
                        else
                            flagB++;
                    }
                    else
                    {
                        if (arr[a][b] == 'B')
                            flagB++;
                        else
                            flagW++;
                    }
                    b++;
                }
                a++;
            }
            min = minFinder(min, flagB);
            min = minFinder(min, flagW);
            j++;
        }
        i++;
    }
    printf("%d", min);
}
