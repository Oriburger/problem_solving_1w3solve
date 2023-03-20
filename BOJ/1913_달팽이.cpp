#include <bits/stdc++.h>
using namespace std;

int n, target, ans[2];
const int dy[4] = {-1, 0, 1, 0};
const int dx[4] = {0, 1, 0, -1};
vector<vector<int> > board; 

bool IsInRange(int y, int x)
{
	return (y>=0 && x>=0 && y<n && x<n);
}

void createMaze(int y, int x, int dir, int val)
{
	if(!IsInRange(y, x)) return;
	if(val == target) ans[0]=y+1, ans[1]=x+1;

	board[y][x] = val;

	const int ny = y + dy[dir], nx = x + dx[dir];
	const int nny = ny + dy[(dir+1)%4], nnx = nx + dx[(dir+1)%4];
	int nextDir = dir;
	
	if(IsInRange(nny, nnx)) 
		nextDir = board[ny+dy[(dir+1)%4]][nx+dx[(dir+1)%4]] == 0 ? (dir+1)%4 : dir;

	createMaze(ny, nx, nextDir, val+1);
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	cin>>n>>target;

	board = vector<vector<int> >(n, vector<int>(n, 0));

	createMaze(n/2, n/2, 0, 1);	

	for(int i=0; i<n; i++)
	{
		for(int j=0; j<n; j++)
			cout<<board[i][j]<<' ';
		cout<<'\n';
	}
	cout<<ans[0]<<' '<<ans[1]<<'\n';


	return 0;
}
