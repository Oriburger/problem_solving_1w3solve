#include <iostream>
#include <queue>
#include <vector>
#include <utility>
#include <algorithm>
using namespace std;

const int dy[4] = {1, -1, 0, 0};
const int dx[4] = {0, 0, 1, -1};

struct Pos{ int y; int x; };

int n, m;
char board[50][50];
int visited[50][50][(1<<6)];
Pos start;

int BFS(Pos start)
{
	queue<pair<Pos, int> > q;
	q.push({start, 0});
	visited[start.y][start.x][0]=0;

	while(!q.empty())
	{
		Pos curr = q.front().first;
		int curState = q.front().second;
		q.pop();

		if(board[curr.y][curr.x]=='1')
			return visited[curr.y][curr.x][curState];

		for(int i=0; i<4; i++)
		{
			Pos next = {curr.y + dy[i], curr.x + dx[i]};
			int nextState = curState;

			if(next.y<0 || next.y>=n || next.x<0 || next.x>=m) continue;
			if(board[next.y][next.x]=='#') continue;

			if(board[next.y][next.x]>='a' && board[next.y][next.x]<='f')
				nextState |= (1<<(board[next.y][next.x]-'a'));

			else if((board[next.y][next.x]>='A' && board[next.y][next.x]<='F'))
				if(!(nextState & (1<<(board[next.y][next.x]-'A')))) continue;

			if(visited[next.y][next.x][nextState]) continue;

			q.push({next, nextState});
			visited[next.y][next.x][nextState]=visited[curr.y][curr.x][curState]+1;
		}
	}
	return -1;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin>>n>>m;

	for(int i=0; i<n; i++)
	for(int j=0; j<m; j++)
	{
		cin>>board[i][j];
		if(board[i][j]=='0')
			start = {i, j};
	}

	cout<<BFS(start)<<'\n';

	return 0;
}
