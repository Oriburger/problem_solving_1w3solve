#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>
using namespace std;

const int INF = 2147000000;
const int dy[4] = {-1, 1, 0, 0};
const int dx[4] = {0, 0, -1, 1};

bool flag = false;
int n, m, board[50][50], ans;
int cache[50][50];
bool visited[50][50];

int DFS(int y, int x)
{
	if(y<0 || x<0 || y>=n || x>=m || board[y][x]==-1) return 0;
	if(visited[y][x])
	{
		cout<<-1<<'\n';
		exit(0);
	}
	
	int &ret = cache[y][x];
	if(ret != -1) return ret;
	
	ret = 1;
	visited[y][x] = true;
	for(int d=0; d<4; d++)
	{
		int ny = y + dy[d] * board[y][x];
		int nx = x + dx[d] * board[y][x];
		
		ret = max(ret, DFS(ny, nx)+1);
	}
	visited[y][x] = false;
	return ret;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	
	cin>>n>>m;
	
	for(int i=0; i<n; i++)
		for(int j=0; j<m; j++)
		{
			char c; cin>>c;
			board[i][j] = (c=='H' ? -1 : c-'0');
		}
	
	memset(cache, -1, sizeof(cache));
	cout<<DFS(0, 0)<<'\n';
	
	return 0;
}
