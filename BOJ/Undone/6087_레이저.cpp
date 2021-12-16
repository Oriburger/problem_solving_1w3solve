#include <iostream>
#include <utility>
#include <queue>
using namespace std;

typedef pair<int,int> P;

P st = {-1,-1}, fin; //레이저 pos 
int w, h, ans;
int board[101][101];
int visited[101][101];

const int dy[4]={1,-1,0,0};
const int dx[4]={0,0,1,-1};

int BFS(int y, int x)
{
	queue<P> q;
	q.push({y, x});
	
	while(!q.empty())
	{
		P curr = q.top();
		q.pop();
		
		for(int i=0; i<4; i++)
		{
			P next = make_pair(curr.first + dy[i], curr.second + dx[i]);
				
			if(next.first < 0 || next.second < 0
				|| next.first >= w || next.second >=h
				|| board[next.first][next.second] != '.')
					continue;
			
			q.push(next);
			visited[next.first][next.second] = 1;
		}
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	
	cin>>w>>h;
	
	// Input
	for(int i=0; i<w; i++)
	{
		for(int j=0; j<h; j++)
		{
			cin>>board[i][j];
			
			if(board[i][j]=='C')
			{
				if(st.first==-1)
					st = make_pair(i, j);
				else
					fin = make_pair(i, j);			
			}
		}
	}
	
	BFS(st.first, st.second);
	
	
	return 0;
}
