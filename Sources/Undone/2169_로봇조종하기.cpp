#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>
using namespace std;

const int dy[3]={1, 0, 0};
const int dx[3]={0, 1, -1};
const int INF = 2147000000;

int n, m;
vector<vector<int> > board, cache;
vector<vector<bool> > visited;

int DFS(int y, int x, int dir)
{
	int &ret = cache[y][x][dir];

	if(ret != INF) return ret;
	if(y==n-1 && x==m-1) return ret = board[y][x];

	ret = board[y][x];
	int temp = 0;
	for(int i=0; i<3; i++)
	{
		int ny = y + dy[i];
		int nx = x + dx[i];

		if(visited[ny][nx]) continue;
		if(ny<0 || nx<0 || ny>=n || nx>=m) continue;

		visited[ny][nx]=true;
		temp = max(temp, DFS(ny, nx));
		visited[ny][nx]=false;
	}
	ret += temp;

	return ret; 
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	
	cin>>n>>m;
	
	board.resize(n, vector<int>(m, 0));
	cache.resize(n, vector<int>(m, INF));
	visited.resize(n, vector<bool>(m, false));

	for(int i=0; i<n; i++)
		for(int j=0; j<n; j++)
			cin>>board[i][j];

	DFS(0, 0);

	for(int i=0; i<n; i++)
	{
		for(int j=0; j<m; j++)
		{
			cout<<cache[i][j]<<' ';
		}
		cout<<'\n';
	}

	cout<<cache[0][0]<<'\n';

	return 0;
}
