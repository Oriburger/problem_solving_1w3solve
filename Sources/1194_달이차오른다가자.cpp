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
//visited[i][j][state] :  {i, j} 좌표에서 열쇠 보유 상태가 state인 경우의 이동 수

int BFS(Pos start)
{
	queue<pair<Pos, int> > q; //마지막 원소인 int는 열쇠 보유 상태를 나타냄
	q.push({start, 0}); //처음에는 아무것도 안가지고 있음 
	visited[start.y][start.x][0]=0; //출발 지점 이동 수는 0

	while(!q.empty())
	{
		Pos curr = q.front().first; //현재 좌표
		int curState = q.front().second; //현재 열쇠 보유 상태 
		q.pop();

		if(board[curr.y][curr.x]=='1') //탈출 지점이라면 정답 반환
			return visited[curr.y][curr.x][curState];

		for(int i=0; i<4; i++) //상하좌우 탐색
		{
			Pos next = {curr.y + dy[i], curr.x + dx[i]}; //다음 좌표
			int nextState = curState; //다음 상태

            //범위를 벗어난다면?
			if(next.y<0 || next.y>=n || next.x<0 || next.x>=m) continue; 
            //다음 좌표가 벽이라면
			if(board[next.y][next.x]=='#') continue;
           
            //열쇠를 찾았다, nextState를 갱신하자
			if(board[next.y][next.x]>='a' && board[next.y][next.x]<='f')
				nextState |= (1<<(board[next.y][next.x]-'a'));
           
            //문을 발견, 열쇠가 없다면 continue
			else if((board[next.y][next.x]>='A' && board[next.y][next.x]<='F'))
				if(!(nextState & (1<<(board[next.y][next.x]-'A')))) continue;
           
            //이미 방문한 경우라면 continue
			if(visited[next.y][next.x][nextState]) continue;
            
            //큐에 넣어주고 visited 갱신 
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
    
    Pos start;
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
