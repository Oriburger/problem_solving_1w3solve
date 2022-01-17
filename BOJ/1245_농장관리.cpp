#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

typedef pair<int, int> P;

const int dy[8] = {1, 1, 1, 0, -1, -1, -1, 0};
const int dx[8] = {-1, 0, 1, 1, 1, 0, -1, -1};

int n, m, board[100][70], ans;
bool visited[100][70];

bool IsPeak(const int y, const int x)
{
	bool ret = true;
	queue<P> q;
	q.push({y, x});
	visited[y][x] = true;
	
	while(!q.empty())
	{
		const int cy = q.front().first;
		const int cx = q.front().second;
		q.pop();

		bool flag = false;
		for(int d=0; d<8; d++)
		{
			const int ny = cy + dy[d];
			const int nx = cx + dx[d];

			if(ny<0 || nx<0 || ny>=n || nx>=m) continue;
			if(board[cy][cx] < board[ny][nx]) ret = false;
			if(board[cy][cx] != board[ny][nx]) continue;
			if(visited[ny][nx]) continue;

			q.push({ny, nx});
			visited[ny][nx] = true;
		}
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
			if(!visited[i][j])
				ans += IsPeak(i, j);

	cout<<ans<<'\n';

	return 0;
}
