#include <iostream>
#include <vector>
#include <queue>
#include <utility>
#include <algorithm>
using namespace std;

const int dy[3] = {-1, 0, 1};
int r, c, answer = 0; bool flag;
char board[10001][501];

void DFS(int y, int x)
{
	if(flag) return;
	if(x==c-1)
	{
		answer++;
		flag = true;
		return;
	}

	for(int d=0; d<3; d++)
	{
		int ny = y + dy[d];
		int nx = x + 1;
		if(nx>=c || ny<0 || ny>=r) continue;
		if(board[ny][nx] != '.') continue;

		board[ny][nx] = '@';
		DFS(ny, nx);
		if(flag) break;
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	
	cin>>r>>c;
	for(int i=0; i<r; i++)
		for(int j=0; j<c; j++)
			cin>>board[i][j];
	
	for(int i=0; i<r; i++)
	{
		flag = false;
		board[i][0] = '@';
		DFS(i, 0);
		if(!flag) board[i][0] = '.';
	}

	cout<<answer<<'\n';

	return 0;
}
