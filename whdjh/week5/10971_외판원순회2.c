#include <stdio.h>
#define TRUE 1
#define FALSE 0

int w[10][10], check[10], n, min = 987654321, sum = 0;

void dfs(int num, int depth)
{
	if(depth == n)
	{
		if(w[num][0] != 0)
		{
			sum += w[num][0];
			if(min > sum)
				min = sum;
			sum -= w[num][0];
		}
		return ;
	}
	for(int i = 0; i < n; i++)
	{
		if(w[num][i] != 0 && check[i] == FALSE)
		{
			if(min > sum + w[num][i])
			{
				sum += w[num][i];
				check[i] = TRUE;
				dfs(i, depth + 1);
				sum -= w[num][i]; 				//이전에 더했던 비용 제외 시키기
				check[i] = FALSE;
			}
		}
	}
}

int main()
{
	scanf("%d", &n);
	for(int i = 0; i < n; i++)
	{
		for(int j = 0; j < n; j++)
			scanf("%d", &w[i][j]);
	}
	check[0] = 1;								//처음부터 0으로 하게되면 반복문에서 조건문이 걸려서 바로 종료되서 1로 초기화해서 돌게 했음!
	dfs(0,1); 
	printf("%d", min);
	return 0;
}