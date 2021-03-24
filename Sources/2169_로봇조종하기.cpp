#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>
using namespace std;

const int dy[3]={1, 0, 0};
const int dx[3]={0, 1, -1};
const int INF = 2147000000;

int n, m;
int cache[1001][1001][3];
int board[1001][1001];
bool visited[1001][1001];

int DFS(int y, int x, const int dir)
{
	int &ret = cache[y][x][dir];

	if(y==n-1 && x == m-1) return board[y][x];
	if(ret != -INF) return ret;

	visited[y][x]=true;
	for(int i=0; i<3; i++)
	{
		int ny = y+dy[i];
		int nx = x+dx[i];

		if(ny<0 || nx<0 || ny>=n || nx>=m) continue;
		if(visited[ny][nx]) continue;

		ret = max(ret, board[y][x]+DFS(ny, nx, i));
	}
	visited[y][x]=false;
	
	return ret;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	
	cin>>n>>m;

	for(int i=0; i<n; i++)
	{		
		for(int j=0; j<m; j++)
		{
			cin>>board[i][j];
			cache[i][j][0]=cache[i][j][1]=cache[i][j][2]=-INF;
		}
	}

	cout<<DFS(0, 0, 0)<<'\n';

	return 0;
}
