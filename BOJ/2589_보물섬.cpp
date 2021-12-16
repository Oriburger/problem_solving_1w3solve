#include <iostream>
#include <queue>
#include <cstring> //memset
using namespace std;

struct Pos{ int y; int x; int val; };

const int dy[4]={1,-1,0,0};
const int dx[4]={0,0,1,-1};

char board[50][50];
int visited[50][50];
int n, m, answer = 0;

int BFS(int y, int x)
{
	int ret = 1;
	queue<Pos> q;
	q.push({y, x, 1});
	visited[y][x]=1;
		
	while(!q.empty())
	{
		Pos curr = q.front();
		q.pop();
		
		for(int i=0; i<4; i++)
		{
			Pos next = {curr.y + dy[i], curr.x + dx[i], curr.val+1};
			
			if(next.y < 0 || next.x < 0 
				|| next.y >= n || next.x >= m) continue;
			if(visited[next.y][next.x]!=0) continue;
			if(board[next.y][next.x]=='W') continue;
			
			q.push(next);
			visited[next.y][next.x]=next.val;
			ret = max(ret, next.val);
		}
	}
	return ret;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	
	cin>>n>>m;
	
	for(int i=0; i<n; i++)
	for(int j=0; j<m; j++)
		cin>>board[i][j];
	
	for(int i=0; i<n; i++)
	for(int j=0; j<m; j++)
	{
		if(board[i][j]=='L')
		{
			answer = max(answer, BFS(i, j)-1);
			for(int k=0; k<n; k++)
				memset(visited[k], 0, sizeof(int) * m);
		}
	}
	
	cout<<answer<<'\n';
	
	return 0;
}
