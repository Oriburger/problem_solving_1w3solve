#include <iostream>
#include <vector>
#include <algorithm>
#define UP 0
#define DOWN 1
#define LEFT 2
#define RIGHT 3
using namespace std;

typedef vector<vector<int> > vec2nd;

int GetMaxBlock(const vec2nd &board)
{
	int ret = 0;

	for(int i=0; i<board.size(); i++)
		for(int j=0; j<board.size(); j++)
			ret = max(ret, board[i][j]);

	return ret;
}

void MoveBoard(const int dir, vec2nd &board)
{
	const int start = ((dir==RIGHT || dir==DOWN) ? board.size()-1 : 0);
	const int end = abs(start - ((int)board.size()-1));
	const int d = ((dir==RIGHT || dir==DOWN) ? -1 : 1);

	for(int i=0; i<board.size(); i++)
	{
		const bool flag[3] = {true, false, true};
		for(int k=0; k<3; k++)
		{
			for(int j=start; j!=end; j+=d)
			{
				int &curr = (dir==RIGHT || dir==LEFT) ? board[i][j] : board[j][i];
				int &next = (dir==RIGHT || dir==LEFT) ? board[i][j+d] : board[j+d][i];

				if(flag[k] && curr == 0 && next != 0) 
				{
					swap(curr, next);
					j=start-d;
				}
				if(!flag[k] && curr && next && curr == next) 
				{
					curr += next;
					next = 0;
				}
			}
		}		
	}
}

int GetAnswer(const int depth, vec2nd &board)
{
	if(depth == 5) return GetMaxBlock(board);

	int ret = 0;
	const vec2nd tmp = board;
	
	for(int dir=0; dir<4; dir++)
	{
		MoveBoard(dir, board);
		ret = max(ret, GetAnswer(depth+1, board));
		board = tmp;
	}
	return ret;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int n;
	vec2nd board;

	cin>>n;

	board = vec2nd(n, vector<int>(n, 0));
	for(int i=0; i<n; i++)
		for(int j=0; j<n; j++)
			cin>>board[i][j];

	cout<<GetAnswer(0, board)<<'\n';

	return 0;
}
