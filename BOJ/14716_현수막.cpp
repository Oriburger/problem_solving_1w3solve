#include <iostream>
#include <vector>
using namespace std;

const int dy[8] = {1, 1, 1, 0, -1, -1, -1, 0};
const int dx[8] = {-1, 0, 1, 1, 1, 0, -1 ,-1};

int n, m, ans, board[251][251];
bool visited[251][251];

void DFS(int y, int x)
{
	visited[y][x] = true;
	
	for(int d=0; d<8; d++)
	{
		int ny = y + dy[d];
		int nx = x + dx[d];
		
		if(ny<0 || nx<0 || ny>=n || nx>=m) continue;
		if(visited[ny][nx] || !board[ny][nx]) continue;
		
		DFS(ny, nx);
	}
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
			if(!visited[i][j] && board[i][j])
			{	
				DFS(i, j);
				ans++;
			}
	
	cout<<ans<<'\n';
	
	return 0;
}
