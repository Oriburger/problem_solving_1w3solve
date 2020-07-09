#include <cstdio>
#include <algorithm>
using namespace std;

int main()
{
	int n, m, answer=0;
	int board[51][51];
	
	scanf("%d %d", &n, &m);
	
	for(int i=1; i<=n; i++)
		for(int j=1; j<=m; j++)
			scanf("%1d", &board[i][j]);
	
	for(int a=1; a<=n; a++)
	{
		for(int b=1; b<=m; b++)
		{
			for(int c=a; c<=n; c++)
			{
				for(int d=b; d<=m; d++)
				{
					if(board[a][b]==board[c][d] 
					 && board[c][b]==board[a][b] 
					 && board[c][b]==board[a][d] && (c-a)==(d-b))
					{
					//	printf("%d %d, %d %d : ", a, b, c, d);
					//	printf("%d %d %d %d\n", board[a][b], board[c][d], board[a][d], board[b][c]);
						answer=max(answer, (c-a+1)*(d-b+1));
					}
				}
			}
		}
	}
	
	printf("%d\n", answer);
	
	return 0;
}
