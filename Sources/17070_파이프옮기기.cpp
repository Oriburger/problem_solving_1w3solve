#include <iostream>
#include <cstring>
using namespace std;

int n;
int board[17][17];
int cache[17][17];
const int dy[3]={0, 1, 1};
const int dx[3]={1, 0, 1};

//(y, x) ~ (n, n) 방법의 수, dir 0 가로, 1 세로, 2 대각선
int GetAnswer(int y, int x, const int dir)
{
	int &ret = cache[y][x];
	if(y==n-1 && x==n-1) return ret=1;

	ret = 0;
	for(int i=0; i<3; i++)
	{
		if((dir==0 && i==1) || (dir==1 && i==0)) continue;

		int ny = y + dy[i];
		int nx = x + dx[i];

		if(ny >= n || nx >= n) continue;
		if(i==2 && (board[ny-1][nx]==1 || board[ny][nx-1]==1)) continue;
		if(board[ny][nx]==1) continue;

		ret += GetAnswer(ny, nx, i);
	}

	return ret;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin>>n;

	for(int i=0; i<n; i++)
	for(int j=0; j<n; j++)
	{
		cin>>board[i][j];
		cache[i][j]=-1;
	}
	
	cout<<GetAnswer(0, 1, 0)<<'\n';

	return 0;
}
