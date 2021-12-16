#include <iostream>
#include <queue>
#include <utility>
#include <cstring>
using namespace std;

const int dy[8]={1,1,1,0,-1,-1,-1,0};
const int dx[8]={-1,0,1,1,1,0,-1,-1};

int m, n;
char board[101][101];
bool visited[101][101];

void BFS(int y, int x)
{
	queue<pair<int,int> > q;
	q.push({y, x});
	visited[y][x] = true;
	
	while(!q.empty())
	{
		pair<int, int> curr = q.front();
		q.pop();
		
		for(int i=0; i<8; i++)
		{
			int ny = dy[i] + curr.first;
			int nx = dx[i] + curr.second;
			
			if(board[ny][nx]!='@') continue;
			if(ny<=0 || nx<=0 || ny>m || nx>n) continue;
			if(visited[ny][nx]) continue;
			
			visited[ny][nx] = true;
			q.push({ny, nx});
		}
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	
	while(1)
	{	
		cin>>m>>n;
		
		if(m==0) break;
		
		for(int i=1; i<=m; i++)
			for(int j=1; j<=n; j++)
				cin>>board[i][j];
	
		int cnt=0;
		for(int i=1; i<=m; i++)
		for(int j=1; j<=n; j++)
			if(board[i][j]=='@' && !visited[i][j])
			{
				BFS(i, j);
				++cnt;
			}
		
		cout<<cnt<<'\n';
		
		for(int i=1; i<=m; i++)
		{
			memset(board[i], 0, sizeof(char)*(n+1));
			memset(visited[i], 0, sizeof(bool)*(n+1));
		}
	}
	
	return 0;
}
