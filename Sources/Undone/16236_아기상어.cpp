#include <iostream>
#include <queue>
#include <vector>
using namespace std;

struct Pos{ int y; int x; };

int n, board[21][21];
vector<Pos> fish;
Pos bsPos; //baby shark du dududududu
int bsSize=2;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin>>n;

	for(int i=1; i<=n; i++)
	{
		for(int j=1; j<=n; j++)
		{
			cin>>board[i][j];
			if(board[i][j]==9) bsPos = {i, j};
			if(board[i][j]==1) fish.push_back({i, j});
		}
	}
	

	return 0;
}
