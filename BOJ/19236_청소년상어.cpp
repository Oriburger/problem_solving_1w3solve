#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>
#define SHARK 17
using namespace std;

struct NODE { int id; int dir; }; 
struct POS { int y; int x; };

const int dy[8] = {-1, -1, 0, 1, 1, 1, 0, -1}; //방향을 나타내는 배열
const int dx[8] = {0, -1, -1, -1, 0, 1, 1, 1};
NODE board[4][4];

/* 보드에서 id를 찾아서 해당 좌표를 반환한다*/
POS GetBoardPos(int id) 
{
	for(int i=0; i<4; i++) //보드의 크기가 4*4이기 때문에, 완전탐색이 가능
	for(int j=0; j<4; j++)
		if(board[i][j].id==id) 
			return{i, j};

	return {-1, -1}; //보드에 존재하지 않는다면?
}

/* 물고기를 이동한다 */
void MoveFish(POS pos)  
{
	int& dir = board[pos.y][pos.x].dir; //물고기의 방향
	
	for(int i=0; i<8; i++)
	{
		POS next = {pos.y + dy[dir], pos.x + dx[dir]};

		//범위를 벗어나거나, 해당 칸에 상어가 있다면?
		if(next.y < 0 || next.x < 0 || next.y >=4  
			|| next.x >= 4 || board[next.y][next.x].id == SHARK) 
		{
			dir += 1; //방향을 반시계 방향으로 45도 튼다
			dir %= 8;
			continue;
		}
		//이동이 가능하다면? 해당 칸으로 이동
		swap(board[next.y][next.x], board[pos.y][pos.x]); 
		return; //그리고 return;
	}
	return;
}

/* 상어가 먹을 수 있는 최대의 물고기 id 합을 반환한다.*/
int Answer() //인자로 상어의 좌표를 전달해도 됨.
{
	int ret = 0;
	NODE boardTemp[4][4]; //backtrack을 위해 이전 단계를 저장 할 배열
	
	for(int i=0; i<4; i++) //변경 이전 배열의 상태를 저장
		for(int j=0; j<4; j++)
			boardTemp[i][j] = board[i][j];
	
	for(int id=1; id<=16; id++) //먼저 물고기들이 이동
	{
		POS fishPos = GetBoardPos(id);
		if(fishPos.y != -1)
			MoveFish(fishPos);
	}
	
	POS sharkPos = GetBoardPos(SHARK);
	int sharkDir = board[sharkPos.y][sharkPos.x].dir;
	for(int i=1; i<=4; i++) 
	{
		//상어의 다음 이동 좌표
		POS next = {sharkPos.y + dy[sharkDir]*i, sharkPos.x + dx[sharkDir]*i}; 

		//보드의 범위를 벗어나거나, 다음 칸이 비어있다면 continue
		if(next.y < 0 || next.x  < 0 || next.y >= 4 || next.x >= 4) continue;
		if(board[next.y][next.x].id == -1) continue;
		
		NODE temp = board[next.y][next.x]; //backtrack을 위해 board[next]의 정보를 저장
		board[sharkPos.y][sharkPos.x] = {-1, -1}; //상어가 이동! 원래 좌표는 빈 칸이 됨.
		board[next.y][next.x] = {SHARK, temp.dir}; //다음 칸으로 상어가 이동, 해당 칸에 물고기의 방향을 가짐 
		
		ret = max(ret, Answer() + temp.id); //최댓값 도출
		
		board[sharkPos.y][sharkPos.x] = {SHARK, sharkDir}; //backtrack
		board[next.y][next.x] = temp; //backtrack
	}
	
	for(int i=0; i<4; i++)
		for(int j=0; j<4; j++)
			board[i][j] = boardTemp[i][j]; //보드를 이전 단계로
	
	return ret;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	for(int i=0; i<4; i++)
		for(int j=0; j<4; j++)
		{
			cin>>board[i][j].id>>board[i][j].dir; //입력 
			board[i][j].dir -= 1;
		}

	int answer = board[0][0].id; //최초로 먹은 물고기도 answer에 더함
	NODE shark = {SHARK, board[0][0].dir}; //상어가 {0,0}으로 간다 
	board[0][0] = shark;

	answer += Answer();
	
	cout<<answer<<'\n';

	return 0;
}
