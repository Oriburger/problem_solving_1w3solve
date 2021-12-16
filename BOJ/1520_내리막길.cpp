#include <iostream>
#include <cstring>
using namespace std;

const int dy[4]={0,0,1,-1};
const int dx[4]={1,-1,0,0};

int m, n, answer=0;
int board[501][501];
int check[501][501];

int DFS(int y, int x)
{
	if(y<0 || x<0 || y>=m || x>=n) return 0;
	if((y==m-1 && x==n-1))	return 1;

	if(check[y][x]!=-1) return check[y][x];
	
	check[y][x]=0;
	for(int i=0; i<4; i++)
	{
		int ny = y + dy[i];
		int nx = x + dx[i];

		if(board[y][x]>board[ny][nx])
			check[y][x] += DFS(ny, nx);
	}
	return check[y][x];
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin>>m>>n;

	for(int i=0; i<m; i++)
	{
		memset(check[i], -1, sizeof(int)*n);
		for(int j=0; j<n; j++)
			cin>>board[i][j];
	}

	cout<<DFS(0,0)<<'\n';

	return 0;
}
