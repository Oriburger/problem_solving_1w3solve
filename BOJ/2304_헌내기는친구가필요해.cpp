#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n, m, sy, sx, cnt;
char arr[600][600];
bool visited[600][600];

const int dy[4] = {1, -1, 0, 0};
const int dx[4] = {0, 0, 1, -1};

void DFS(int y, int x)
{
	if(arr[y][x] == 'P') cnt++;
	visited[y][x] = true;
	
	for(int d=0; d<4; d++)
	{
		int ny = y + dy[d];
		int nx = x + dx[d];
		
		if(ny < 0 || nx < 0 || ny >= n || nx >= m) continue;
		if(visited[ny][nx]) continue;
		if(arr[ny][nx] == 'X') continue;
		
		DFS(ny, nx);
	}
}

int main()
{
	cin>>n>>m;
	for(int i=0; i<n; i++)
		for(int j=0; j<m; j++)
		{
			cin>>arr[i][j];
			if(arr[i][j] == 'I')
				sy = i, sx = j;
		}
			
	DFS(sy, sx);
	
	if(cnt > 0) cout<<cnt<<'\n';
	else cout<<"TT\n";
	
	return 0;
}
