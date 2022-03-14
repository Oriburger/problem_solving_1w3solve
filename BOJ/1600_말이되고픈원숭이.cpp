#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
#include <algorithm>
using namespace std;

struct Pos { int y; int x; int k; };

const int dy[4] = {-1, 1, 0, 0};
const int dx[4] = {0, 0, -1, 1};
const int ky[8] = {-2, -1, 1, 2, 2, 1, -1, -2};
const int kx[8] = {1, 2, 2, 1, -1, -2, -2, -1};
const int INF = 2147000000;

int k, w, h, board[201][201], dist[201][201][31];

int BFS()
{
	queue<Pos> q;
	q.push({0, 0, k});

	memset(dist, -1, sizeof(dist));
	dist[0][0][k] = 0;
		
	while(!q.empty())
	{
		Pos curr = q.front();
		q.pop();
		
		for(int sel=(curr.k<=0 ? 1 : 0); sel<2; sel++)
		{
			int fin = (!sel ? 8 : 4);
			
			for(int d=0; d<fin; d++)	
			{
				const int ny = !sel ? ky[d]+curr.y : dy[d]+curr.y;
				const int nx = !sel ? kx[d]+curr.x : dx[d]+curr.x;
				const int next_k = !sel ? curr.k-1 : curr.k;
				
				if(next_k < 0) continue;
				if(ny<0 || nx<0 || ny>=h || nx>=w) continue;
				if(board[ny][nx]==1) continue;
				if(dist[ny][nx][next_k] != -1) continue;
				
				dist[ny][nx][next_k] = dist[curr.y][curr.x][curr.k] + 1;
				q.push({ny, nx, next_k});
			}
		}
	}
	
	int ret = INF;
	for(int i=0; i<=k; i++)
		if(dist[h-1][w-1][i] != -1)
			ret = min(ret, dist[h-1][w-1][i]);
	
	return ret == INF ? -1 : ret;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	
	cin>>k>>w>>h;
	
	for(int i=0; i<h; i++)
		for(int j=0; j<w; j++)
			cin>>board[i][j];
	
	cout<<BFS()<<'\n';
	
	return 0;
}
