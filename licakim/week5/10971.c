//틀렸어..

#include<stdio.h>

int map[11][11];
int visit[11] ={0,};
int N;
int min;

void travel(int start,int i,int total)
{
    if(i == N-1)
    {
        if(total < min) min = total;
        return;
    }
    
    for(int k=0; k<N; k++)
    {
        if(start!= k && visit[k] == 0)
        {
            visit[k] = 1;
            visit[start] = 1;
            total +=map[start][k];
            travel(k,i+1,total);
            visit[k] = 0;
            visit[start] = 0;

        }
    }

}

int main()
{
    scanf("%d",&N);

    for(int i = 0; i< N; i++)
    {
        for(int j = 0; j< N; j++)
        {
            scanf("%d", &map[i][j]);
            min += map[i][j];
        }
    }

    for(int i = 0; i<N; i++)
        travel(i,0,0);
    printf("%d", min);
}


