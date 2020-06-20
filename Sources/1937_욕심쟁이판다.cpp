#include <iostream>
using namespace std;

const int dy[4]={0,0,1,-1};
const int dx[4]={1,-1,0,0};

int n, answer=0;
int board[500][500];
int cache[500][500];

int GetDist(int y, int x)
{
	int& ret = cache[y][x];
	
	if(ret!=-1) return ret;
	
	ret = 1;
	for(int i=0; i<4; i++)
	{
		int ny = y+dy[i];
		int nx = x+dx[i];
		
		if(ny<0 || nx<0 || ny>=n || nx>=n) 
			continue;
		
		if(board[y][x] < board[ny][nx])
			ret = max(ret, GetDist(ny, nx)+1);
	}
	
	return ret;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	
	cin>>n;
	
	for(int i=0; i<n; i++)
	for(int j=0; j<n; j++)
	{
		cin>>board[i][j];
		cache[i][j]=-1;
	}
	
	for(int i=0; i<n; i++)
	for(int j=0; j<n; j++)
		answer = max(answer, GetDist(i, j));

	cout<<answer<<'\n';

	return 0;
}
