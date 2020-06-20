#include <cstdio>
#include <algorithm>
using namespace std;

int n, m, answer;
int board[1000][1000];
int cache[1000][1000];

int Square(int y, int x)
{
	int& ret = cache[y][x];
	
	if(ret != -1) return ret;
	ret = 1;
	
	for(int i=1; i<=min((n-1)-x, (m-1)-y); i++)
	{
		bool flag=true; //Square 함수 호출 여부 true false 
		for(int j=1; j<=i; j++)
		{
			if(board[y+j][x] != 1 || board[y][x+j] != 1)
			{
				flag = false;
				break;
			}
		}
		
		if(flag && board[y+1][x+1]==1)
		{
			int nextVal = Square(y+1, x+1);
			if(nextVal >= i)
				ret = max(ret, ret+1);
		}
	}
	
	return ret;
}

int main()
{
	scanf("%d %d", &n, &m);

	for(int i=0; i<n; i++)
	for(int j=0; j<m; j++)
	{
		scanf("%1d", &board[i][j]);
		cache[i][j]=-1;
	}

	for(int i=0; i<n; i++)
	for(int j=0; j<m; j++)
		if(board[i][j]==1)
			answer = max(answer, Square(i, j));
	
	for(int i=0; i<n; i++)
	{
		for(int j=0; j<m; j++)
			printf("%2d", cache[i][j]);
		printf("\n");
	}

	printf("%d\n", answer*answer);

	return 0;
}
