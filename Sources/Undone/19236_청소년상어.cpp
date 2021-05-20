#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>
using namespace std;

struct NODE { int id; int dir; };
struct POS { int y; int x; };

NODE board[4][4];

POS GetBoardPos(int id);
void MoveFish(POS pos);
int MoveShark(POS pos);

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	for(int i=0; i<4; i++)
		for(int j=0; j<4; j++)
			cin>>board[i][j].id>>board[i][j].dir;
	
	int ans = 1;

	NODE shark = {17, board[0][0].dir};
	board[0][0] = shark;

	while(1)
	{
		for(int id=1; id<=16; id++)
			MoveFish(GetBoardPos(id));

		int temp = MoveShark(GetBoardPos(shark.id));

		if(!temp) break;
		else ans += temp;
	}

	cout<<ans<<'\n';

	return 0;
}

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
	
}

int MoveShark(POS pos)
{

}
