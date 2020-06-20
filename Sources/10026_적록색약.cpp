#include <iostream>
using namespace std;

int n, cnt1=1, cnt2=1;
char pic[100][100];
int visited1[100][100]; //정상 
int visited2[100][100]; //적록색약 
const int dy[4] = {1,-1,0,0};
const int dx[4] = {0,0,1,-1};

void DFS1(int y, int x, char color) //정상 
{
	if(y<0 || x<0 || y>=n || x>=n) return;
	if(pic[y][x] != color) return;
	if(visited1[y][x]!=0) return;
	
	visited1[y][x]=cnt1;
	
	for(int i=0; i<4; i++)
	{
		int ny = y+dy[i];
		int nx = x+dx[i];
		
		DFS1(ny, nx, color);
	}
}

void DFS2(int y, int x, char color) //적록색약 
{
	if(y<0 || x<0 || y>=n || x>=n) return;
	if(visited2[y][x]!=0) return;
	if(pic[y][x] != color)
		if(pic[y][x]*color != 'G'*'R') return;
	
	visited2[y][x]=cnt2;
	
	for(int i=0; i<4; i++)
	{
		int ny = y+dy[i];
		int nx = x+dx[i];
		
		DFS2(ny, nx, color);
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	
	cin>>n;
	
	for(int i=0; i<n; i++)
	for(int j=0; j<n; j++)
		cin>>pic[i][j];
	
	for(int i=0; i<n; i++)
	for(int j=0; j<n; j++)
	{
		if(visited1[i][j]==0)
		{
			DFS1(i, j, pic[i][j]);
			cnt1++;
		}
		if(visited2[i][j]==0)
		{
			DFS2(i, j, pic[i][j]);
			cnt2++;
		}
	}
	cout<<cnt1-1<<' '<<cnt2-1<<'\n';
	
	return 0;
}
