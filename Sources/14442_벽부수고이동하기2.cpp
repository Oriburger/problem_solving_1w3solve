#include <cstdio>
#include <vector>
#include <queue>
#include <utility>
#include <algorithm>
using namespace std;

typedef pair<int,int> P;
const int dy[4]={1,-1,0,0};
const int dx[4]={0,0,1,-1};
const int INF=987654321;

int n, m, k, answer=INF;
int board[1001][1001];
int dist[1001][1001][11];
queue<pair<pair<int, int>, int > > q;

int GetDist()
{
	q.push({{1, 1}, k});
	dist[1][1][k]=1; 
	
	while(!q.empty())
	{
		int cy = q.front().first.first; 
		int cx = q.front().first.second;
		int block = q.front().second;
		q.pop();
	
		if (cy == n && cx == m)
			return dist[cy][cx][block];
		
		for(int i=0; i<4; i++)
		{
			int ny = cy + dy[i];
			int nx = cx + dx[i];
		
			if(ny<1 || nx<1 || ny>n || nx>m) continue;	
					
			if(board[ny][nx]==1 && block)
			{
				if(dist[ny][nx][block-1] != 0) continue;
				dist[ny][nx][block-1] = dist[cy][cx][block]+1;
				q.push({{ny, nx}, block-1});
			}
			else if(board[ny][nx]==0)
			{
				if(dist[ny][nx][block] != 0) continue;
				dist[ny][nx][block] = dist[cy][cx][block]+1;
				q.push({{ny, nx}, block});
			}
		}
	}
	
	return -1;
}

int main()
{
	scanf("%d %d %d", &n, &m, &k);
	
	for(int i=1; i<=n; i++)
	for(int j=1; j<=m; j++)
		scanf("%1d", &board[i][j]);

	printf("%d\n", GetDist());
	
	return 0;
}
