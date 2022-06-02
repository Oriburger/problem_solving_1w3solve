#include <bits/stdc++.h>
using namespace std;

int n, m, ans=0;
const int dy[2] = {1, 0};
const int dx[2] = {0, 1};
char board[51][51];
bool visited[51][51];

void DFS(int y, int x, bool rflag)
{
	visited[y][x]=true;
	
	int ny = y + dy[rflag], nx = x + dx[rflag];
	if(ny >= n || nx >= m) return;
	if(!visited[ny][nx] && board[ny][nx]==board[y][x])
		DFS(ny, nx, rflag);
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
    		if(!visited[i][j])
    		{
    			ans++;
    			DFS(i, j, board[i][j]=='-');
			}
    
    cout<<ans<<'\n';
    
    return 0;
}
