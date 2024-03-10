//=============
//
// 단순 DFS 기반의 완전 탐색에 DP 얹으면 됨
//
//=============

#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>
using namespace std;

int h, w; 
int board[301][301];
int cache[301][301];
const int dy[2] = {1, 0};
const int dx[2] = {0, 1};

int getAnswer(int y, int x)
{	
	int& ret = cache[y][x];
	if(ret != -1) return ret;
	
	ret = 0; 
	for(int d = 0; d < 2; d++)
	{
		int ny = y + dy[d];
		int nx = x + dx[d];
		
		if(ny >= h || nx >= w) continue;
		ret = max(ret, getAnswer(ny, nx) + board[ny][nx]);
	}
	return ret; 
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	cin>>h>>w; 
	
	memset(cache, -1, sizeof(cache));
	
	for(int i=0; i<h; i++)
		for(int j=0; j<w; j++)
			cin>>board[i][j];
			
	cout<<getAnswer(0, 0) + board[0][0]<<'\n';
	
	return 0;
}1
