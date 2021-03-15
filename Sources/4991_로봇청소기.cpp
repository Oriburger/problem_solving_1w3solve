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

Pos stPos; //시작 좌표
int w, h, dirtCnt; //가로, 세로, 더러운 칸 개수
char board[20][20]; //직사각형 모양의 방
int visited[20][20][(1<<10)]; //더러운 칸은 최대 10개 이므로, (1<<10)만큼 할당

int BFS(Pos start)
{
	queue<pair<Pos, int> > q; //좌표에 따라, 상태에 따라 Queue에 push
	q.push({start, 0}); //시작좌표 push, 초기 상태는 0
	visited[start.y][start.x][0] = 0; //초기의 이동 횟수 0

	while(!q.empty()) 
	{
		Pos curr = q.front().first; //현재 좌표 
		int curState = q.front().second; //현재 상태
		q.pop();

		if(curState == ((1<<dirtCnt)-1)) //만약, 방에 있는 먼지들을 모두 청소했다면
			return visited[curr.y][curr.x][curState]; //이동 횟수 반환

		for(int i=0; i<4; i++) //상, 하, 좌, 우 탐색
		{
			Pos next = {curr.y + dy[i], curr.x + dx[i]}; //다음 좌표
			int nextState = curState; //다음 상태

			if(next.y<0 || next.x<0 || next.y>=h || next.x>=w) continue; //out of range
			if(board[next.y][next.x]=='x') continue; //다음 칸이 가구라면 
			if(board[next.y][next.x]>='0' && board[next.y][next.x]<='9') //다음 칸이 먼지라면
				nextState |= (1<<(board[next.y][next.x]-'0')); //nextState 갱신(해당 비트 on)
			
			if(visited[next.y][next.x][nextState]) continue; //다음 좌표&상태가 이미 방문한 상태라면 continue

			//다음 좌표&상태 이동횟수 갱신 및 Queue에 push
			visited[next.y][next.x][nextState] = visited[curr.y][curr.x][curState] + 1; 
			q.push({next, nextState});
		}	
	}
	return -1; //모든 먼지를 치울 수 없다면 -1 반환
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	while(1)
	{
		cin>>w>>h;
		if(!w && !h) break;

		memset(board, 0, sizeof(board));
		memset(visited, 0, sizeof(visited));
		dirtCnt=0;

		for(int i=0; i<h; i++)
		{
			for(int j=0; j<w; j++)
			{
				cin>>board[i][j];
				if(board[i][j]=='o') stPos = {i, j};
				else if(board[i][j]=='*') //먼지가 있는 칸을 숫자로 매겨준다. -> 비트연산 위함
					board[i][j]=(dirtCnt++)+'0'; 
			}
		}

		cout<<BFS(stPos)<<'\n';
	}

	return 0;
}
