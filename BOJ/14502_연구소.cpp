#include <iostream>
#include <utility>
#include <vector>
#define P pair<int,int>
using namespace std;

const int dy[4] = {1,-1,0,0};
const int dx[4] = {0,0,1,-1};

int n, m, answer;
int lab[8][8]; //연구소 지도  
int lab2[8][8]; //DFS 연산을 위한 추가 배열 
vector<P> virusPos;

void DFS(int y, int x) //DFS 
{
	if(y<0 || x<0 || y>=n || x>=m) return;
	if(lab2[y][x]!=0) return;
	
	lab2[y][x]=2;
	
	for(int i=0; i<4; i++)
	{
		int ny = y + dy[i];
		int nx = x + dx[i];
		DFS(ny, nx);
	}
}

void GetMaxArea(int cnt)
{
	if(cnt==3) //벽을 모두 세웠을 경우 
	{
		for(int i=0; i<n; i++)
		for(int j=0; j<m; j++)
			lab2[i][j]=lab[i][j];	
		
		int safeCnt=0;
		
		for(int i=0; i<virusPos.size(); i++)
		{
			lab2[virusPos[i].first][virusPos[i].second] = 0;
			DFS(virusPos[i].first, virusPos[i].second);
		}
		
		for(int i=0; i<n; i++)
		for(int j=0; j<m; j++)
			if(lab2[i][j]==0)
				safeCnt++;
		
		answer=max(safeCnt, answer);		
		
		return;
	}
	
	// 벽을 Pick 
	for(int i=0; i<n; i++)
	for(int j=0; j<m; j++)
		if(lab[i][j]==0)
		{			
			lab[i][j]=1;
			GetMaxArea(cnt+1);
			lab[i][j]=0;
		}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	
	cin>>n>>m;
	
	for(int i=0; i<n; i++)
	for(int j=0; j<m; j++)
	{
		cin>>lab[i][j];
		if(lab[i][j]==2) //virus pos 저장 
			virusPos.push_back({i, j});
	}
	GetMaxArea(0);
	cout<<answer<<'\n';
	
	return 0;
}
