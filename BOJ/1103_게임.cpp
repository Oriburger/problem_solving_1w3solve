#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

const int dy[4] = {-1, 1, 0, 0};
const int dx[4] = {0, 0, -1, 1};

bool flag = false;
int n, m, board[50][50];
int cache[50][50];
bool finished[50][50];

int DFS(int y, int x)
{   
    int &ret = cache[y][x];    
    if(ret != 0) 
    {
        flag = !finished[y][x];
        return ret = (flag ? -1 : ret);
    }
	
	ret = 1;
	for(int d=0; d<4; d++)
	{
		int ny = y + dy[d] * board[y][x];
		int nx = x + dx[d] * board[y][x];
        if(ny<0 || nx<0 || ny>=n || nx>=m || board[ny][nx]==-1) continue;
        
		ret = max(ret, DFS(ny, nx)+1);
        if(flag) return ret = -1;
	}
	finished[y][x]=true; 
	return ret = (flag ? -1 : ret);
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
	
	cout<<DFS(0, 0)<<'\n';
	
	return 0;
}
