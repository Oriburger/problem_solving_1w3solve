#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>
#define SHARK 17
using namespace std;

struct NODE { int id; int dir; };
struct POS { int y; int x; };

const int dy[8] = {-1, -1, 0, 1, 1, 1, 0, -1};
const int dx[8] = {0, -1, -1, -1, 0, 1, 1, 1};
NODE board[4][4];

POS GetBoardPos(int id)
{
	for(int i=0; i<4; i++)
	for(int j=0; j<4; j++)
		if(board[i][j].id==id) 
			return{i, j};

	return {-1, -1};
}

void MoveFish(POS pos)
{
	int& dir = board[pos.y][pos.x].dir;
	
	for(int i=0; i<8; i++)
	{
		POS next = {pos.y + dy[dir], pos.x + dx[dir]};
		bool flag = false;

		if(next.y < 0 || next.x < 0 || next.y >=4 
			|| next.x >= 4 || board[next.y][next.x].id == SHARK)
		{
			dir += 1;
			dir %= 8;
			continue;
		}
		swap(board[next.y][next.x], board[pos.y][pos.x]);
		return;
	}

	return;
}
int Answer()
{
	int ret = 0;
	NODE boardTemp[4][4];
	
	for(int i=0; i<4; i++)
		for(int j=0; j<4; j++)
			boardTemp[i][j] = board[i][j];
	
	for(int id=1; id<=16; id++)
	{
		POS fishPos = GetBoardPos(id);
		if(fishPos.y != -1)
			MoveFish(fishPos);
	}
	
	POS sharkPos = GetBoardPos(SHARK);
	int sharkDir = board[sharkPos.y][sharkPos.x].dir;
	for(int i=1; i<=4; i++)
	{
		POS next = {sharkPos.y + dy[sharkDir]*i, sharkPos.x + dx[sharkDir]*i};

		if(next.y < 0 || next.x  < 0 || next.y >= 4 || next.x >= 4) continue;
		if(board[next.y][next.x].id == -1) continue;
			
		NODE temp = board[next.y][next.x];
		board[sharkPos.y][sharkPos.x] = {-1, -1};
		board[next.y][next.x] = {SHARK, temp.dir};
		
		ret = max(ret, Answer() + temp.id);
		
		board[sharkPos.y][sharkPos.x] = {SHARK, sharkDir};
		board[next.y][next.x] = temp;
	}
	
	for(int i=0; i<4; i++)
		for(int j=0; j<4; j++)
			board[i][j] = boardTemp[i][j];
	
	return ret;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	for(int i=0; i<4; i++)
		for(int j=0; j<4; j++)
		{
			cin>>board[i][j].id>>board[i][j].dir;
			board[i][j].dir -= 1;
		}

	int answer = board[0][0].id;
	NODE shark = {SHARK, board[0][0].dir};
	board[0][0] = shark;

	answer += Answer();
	
	cout<<answer<<'\n';

	return 0;
}
