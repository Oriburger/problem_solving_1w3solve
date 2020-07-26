#include <iostream>
#include <queue>
using namespace std;

struct Pos{ int y; int x; int dist; };

int n, m, board[301][301];
bool visited[301][301];
const int dy[2] = {1, 0};
const int dx[2] = {0, 1};

void Answer(int y, int x)
{	
	queue<Pos> q;
	
	q.push({y, x, 0});
	visited[y][x]=true;
	
	while(!q.empty())
	{
		Pos curr = q.front();
		q.pop();
		
		if(curr.y == n && curr.x == m)
		{
			cout<<curr.dist<<'\n';
			return;
		}
		
		for(int i=0; i<2; i++)
		{
			for(int j=1; j<=board[curr.y][curr.x]; j++)
			{
				int ny = curr.y + dy[i]*j;
				int nx = curr.x + dx[i]*j;
				
				if(ny<=0 || nx<=0 || ny>n || nx>m) continue;
				if(visited[ny][nx]) continue;
				
				visited[ny][nx]=true;
				q.push({ny, nx, curr.dist+1});
			}
		}
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin>>n>>m;
	
	for(int i=1; i<=n; i++)
	for(int j=1; j<=m; j++)
		cin>>board[i][j];
	
	Answer(1, 1);

	return 0;
}
