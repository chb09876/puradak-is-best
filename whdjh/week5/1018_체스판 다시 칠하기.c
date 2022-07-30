#include <stdio.h>
#define min(a, b) (a < b ? a : b)

char chess_board[50][50];

int check(int row, int col, int min)
{
	int w = 0, b =0;
	for(int i = row; i < row + 8; i++) 	//기준이 되는 시작 좌표는 (row, col) 왜 여기선 8이냐면 인데스를 생각해봐라
	{
		for(int j = col; j < col + 8; j++)
		{
			if(((i + j) % 2) == 0)		//검정칸이어야 하는 곳
				chess_board[i][j] == 'B' ? w++ : b++;
			else						//흰색칸이어야 하는 곳	
				chess_board[i][j] == 'B' ? b++ : w++;
		}
	}
	return min(min, min(w, b));
}

int main()
{
	int n, m, min = 64;

	scanf("%d %d", &n, &m);
	for(int i = 0; i < n; i++)
		scanf("%s", &chess_board[i]);
	for(int row = 0; row < n - 7; row++)	//너는 실제 숫자를 기준으로 하기때문에!
	{
		for(int col = 0; col < m - 7; col++)
			min = check(row, col, min);
	}
	printf("%d", min);
	return 0;
}
