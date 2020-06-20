#include <iostream>
#include <utility>
#include <vector>
using namespace std;

const int dy[4]={1,-1,0,0};
const int dx[4]={0,0,1,-1};

int m, n, answer;
int board[500][500];
int cache[500][500];
int visited[500][500];
vector<pair<int,int> > route;

bool Search(int y, int x)
{
	int& ret = cache[y][x];
	
	if(y==m-1 && x==n-1)
	{	
		answer++;
		return true;
	}
	
	if(ret != -1) return ret;
	
	ret=0;
	for(int i=0; i<4; i++)
	{
		int ny = y+dy[i];
		int nx = x+dx[i];
		
		if(ny<0 || nx<0 || ny>=m || nx>=n) continue;
		
		if(board[y][x] > board[ny][nx])
		{
			ret = Search(ny, nx);
		}
	}
	
	return false;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	
	cin>>m>>n;
	
	for(int i=0; i<m; i++)
	for(int j=0; j<n; j++)
	{
		cin>>board[i][j];
		cache[i][j]=-1;
	}
	
	Search(0, 0);
	
	cout<<answer<<'\n';
	
	return 0;
}
