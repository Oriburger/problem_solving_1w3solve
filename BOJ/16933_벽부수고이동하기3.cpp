#include <bits/stdc++.h>
using namespace std;

struct Node{ int y; int x; int block; bool is_night; };

const int dy[4] = {0, 0, 1, -1};
const int dx[4] = {1, -1, 0, 0};

int n, m, k;
char board[1000][1000];
int dist[1000][1000][11][2];

int GetAnswer()
{
	queue<Node> q;
	q.push({0, 0, k, false});
	dist[0][0][k][false] = 1;

	while(!q.empty())
	{
		int cy = q.front().y;
		int cx = q.front().x;
		int block = q.front().block;
		bool is_night = q.front().is_night;
		int cur_dist = dist[cy][cx][block][is_night];
		q.pop();

		if(cy == n-1 && cx == m-1) return dist[cy][cx][block][is_night];

		for(int i=0; i<4; i++)
		{
			int ny = cy + dy[i];
			int nx = cx + dx[i];

			if(ny < 0 || nx < 0 || ny >= n || nx >= m) continue;
			
			if(board[ny][nx]=='1' && block > 0)
			{
				if(is_night)
				{
					if(dist[cy][cx][block][!is_night]) continue;
					q.push({cy, cx, block, !is_night});
					dist[cy][cx][block][!is_night] = cur_dist + 1;
				}
				else
				{
					if(dist[ny][nx][block-1][!is_night]) continue;
					q.push({ny, nx, block-1, !is_night});
					dist[ny][nx][block-1][!is_night] = cur_dist + 1;
				}
			}
			else if(board[ny][nx]=='0')
			{
				if(dist[ny][nx][block][!is_night]) continue;
				q.push({ny, nx, block, !is_night});
				dist[ny][nx][block][!is_night] = cur_dist + 1;
			}
		}
	}
	return -1;
}

int main()
{	
	cin>>n>>m>>k;

	for(int i=0; i<n; i++)
		for(int j=0; j<m; j++)
			cin>>board[i][j];
	
	cout<<GetAnswer();

	return 0;
}
