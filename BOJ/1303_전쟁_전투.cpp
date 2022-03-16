#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

const int dy[4]={-1, 1, 0, 0};
const int dx[4]={0, 0, 1, -1};

int n, m, cnt[2], tmp;
char board[100][100];
bool visited[100][100];

void DFS(int y, int x)
{
	visited[y][x]=true;
	tmp+=1;
	
	for(int d=0; d<4; d++)
	{
		int ny = y + dy[d];
		int nx = x + dx[d];
		
		if(ny<0 || nx<0 || ny>=n || nx>=m) continue;
		if(visited[ny][nx]) continue;
		if(board[y][x]!=board[ny][nx]) continue;
		
		DFS(ny, nx);
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	
	cin>>m>>n;
	
	for(int i=0; i<n; i++)
		for(int j=0; j<m; j++)
			cin>>board[i][j];
	
	for(int i=0; i<n; i++)
	{	
		for(int j=0; j<m; j++)
		{
			if(visited[i][j]) continue;
			DFS(i, j);
			if(board[i][j]=='W') cnt[0] += tmp*tmp;
			else cnt[1] += tmp*tmp;
			tmp=0;
		}
	}
	cout<<cnt[0]<<' '<<cnt[1]<<'\n';
	
	return 0;
}
