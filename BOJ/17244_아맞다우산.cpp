#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
#include <utility>
#include <algorithm>
using namespace std;

struct Pos{ int y; int x; };
const int dy[4] = {1, -1, 0, 0};
const int dx[4] = {0, 0, -1, 1};

Pos stPos;
int w, h, pickCnt; 
char board[50][50];
int visited[50][50][(1<<5)]; 

int BFS(Pos start)
{
	queue<pair<Pos, int> > q; 
	q.push({start, 0}); 
	visited[start.y][start.x][0] = 0;

	while(!q.empty()) 
	{
		Pos curr = q.front().first;
		int curState = q.front().second; 
		q.pop();

		if(curState == ((1<<pickCnt)-1) && board[curr.y][curr.x]=='E') 
			return visited[curr.y][curr.x][curState]; 

		for(int i=0; i<4; i++)
		{
			Pos next = {curr.y + dy[i], curr.x + dx[i]};
			int nextState = curState;

			if(next.y<0 || next.x<0 || next.y>=h || next.x>=w) continue; 
			if(board[next.y][next.x]=='#') continue;
			if(board[next.y][next.x]>='0' && board[next.y][next.x]<='9') 
				nextState |= (1<<(board[next.y][next.x]-'0')); 
			
			if(visited[next.y][next.x][nextState]) continue; 

			visited[next.y][next.x][nextState] = visited[curr.y][curr.x][curState] + 1; 
			q.push({next, nextState});
		}	
	}
	return -1; 
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin>>w>>h;

	memset(board, 0, sizeof(board));
	memset(visited, 0, sizeof(visited));
	pickCnt=0;

	for(int i=0; i<h; i++)
	{
		for(int j=0; j<w; j++)
		{
			cin>>board[i][j];
			if(board[i][j]=='S') stPos = {i, j};
			else if(board[i][j]=='X') 
				board[i][j]=(pickCnt++)+'0'; 
		}
	}
	cout<<BFS(stPos)<<'\n';

	return 0;
}
