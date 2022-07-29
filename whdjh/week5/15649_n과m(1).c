/*백트레킹을 활용한 순열 문제다! 백트레킹이란 해를 찾아가는 도중, 지금의 경로가 해가 될 것  같지 않으면 그 경로를 더이상 가지 않고 되돌아간다.
즉 답이 될만한지 가치를 판단하고 그렇지 않으면 그 부분까지 탐색하는 것을 하지 않고 불필요부분을 쳐내고 올바른 쪽으로 보냄*/
#include <stdio.h>
#define TRUE 1
#define FALSE 0

int n, m, result[1000], check[1000];	//여기서 전역변수를 쓰면 정답이 맞는데 왜 전역변수 말고 내부에 쓰면 안되는지 모르겠다.

void dfs(int depth)
{	
	if(depth == m)						//목표에 도달했다.
	{
		for(int i = 0; i < m; i++)
			printf("%d ", result[i]);	//result에 저장한값 m개 만큼 출력해라
		printf("\n");
	}
	else								//목표에 도달하지 못했다.
	{
		for(int i = 1; i <= n; i++)
		{
			if(check[i] == FALSE)
			{
				result[depth] = i;		//i값을 result에 저장
				check[i] = TRUE;		//방문 표시
				dfs(depth + 1);			//m까지 깊게 들어가라
				check[i] = FALSE;		//백트레킹
			}
		}
	}
}

int main()
{
	scanf("%d %d", &n, &m);
	dfs(0);								//처음부터 다 확인하려고 0부터 시작시킴!
	return 0;
}