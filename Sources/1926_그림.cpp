#include <iostream>
using namespace std;

int n, m, cnt, ans=0;
int board[501][501];
bool visited[501][501];
const int dy[4]={1,-1,0,0};
const int dx[4]={0,0,1,-1};

int DFS(int y, int x)
{
	int ret=1;
	visited[y][x]=true;

	for(int i=0; i<4; i++)
	{
		int ny=y+dy[i];
		int nx=x+dx[i];

		if(ny<0 || nx<0 || ny>=n || nx>=m) continue;
		if(board[ny][nx]==0) continue;
		if(visited[ny][nx]) continue;

		ret += DFS(ny, nx);
	}
	return ret;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin>>n>>m;

	for(int i=0; i<n; i++)
	for(int j=0; j<m; j++)
		cin>>board[i][j];

	
	for(int i=0; i<n; i++)
	for(int j=0; j<m; j++)
		if(!visited[i][j] && board[i][j]==1)
		{
			cnt++;
			ans = max(ans, DFS(i, j));
		}
	
	cout<<cnt<<'\n'<<ans<<'\n';

	return 0;
}
