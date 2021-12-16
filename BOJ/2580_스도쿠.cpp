#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

struct Pos{ int y; int x; };

int board[9][9];
bool flag=false;
vector<Pos> posArr;

void ShowBoard()
{
	for(int i=0; i<9; i++)
	{
		for(int j=0; j<9; j++)
			printf("%d ", board[i][j]);
		printf("\n");
	}
}

bool LineCheck(Pos p)
{
	//----가로----------
	for(int j=0; j<9; j++)
		if(j!=p.x && board[p.y][j] == board[p.y][p.x] ) return false;
	
	//----세로--------
	for(int j=0; j<9; j++)
		if(j!=p.y && board[j][p.x] == board[p.y][p.x] ) return false;

	return true;
}

bool SquareCheck(Pos p)
{
	Pos start = {p.y/3*3, p.x/3*3};

	//----네모칸-------
	for(int i=0; i<3; i++)
		for(int j=0; j<3; j++)
			if(start.y+i!=p.y && start.x+j!=p.x &&
			 board[start.y+i][start.x+j] == board[p.y][p.x] ) return false;
	
	return true;			
}


void Sudoku(int idx)
{
	if(flag) return;
	if(idx == posArr.size())
	{
		flag = true;

		ShowBoard();

		return;
	}
	
	Pos curr = posArr[idx];

	for(int i=1; i<=9; i++)
	{
		board[curr.y][curr.x]=i;
		
		if(LineCheck(curr) && SquareCheck(curr))
			Sudoku(idx+1);
		
		board[curr.y][curr.x]=0;
	}
}

int main()
{
	for(int i=0; i<9; i++)
		for(int j=0; j<9; j++)
		{
			scanf("%d", &board[i][j]);
			if(board[i][j]==0)
				posArr.push_back({i, j});
		}

	if(posArr.size()==0)
		ShowBoard();
	else
		Sudoku(0);

	return 0;
}
