#include <cstdio>
#include <algorithm>
using namespace std;

int n, m, answer;
int board[1000][1000];
int cache[1000][1000];

int Square(int y, int x)
{
	int& ret = cache[y][x];
	
	if(y>=n || x>=m) return 0;
	if(board[y][x] == 0) return ret=0;
	
	if(ret != -1) return ret;
	
	ret = board[y][x];
	
	ret += min(Square(y+1, x), min(Square(y, x+1), Square(y+1, x+1)));
	
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

	printf("%d\n", answer*answer);

	return 0;
}
