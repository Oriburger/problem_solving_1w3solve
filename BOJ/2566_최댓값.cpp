#include <bits/stdc++.h>
using namespace std;

int board[9][9];
int maxValue = -1;
pair<int, int> maxPos;

int main() 
{
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	
	for(int i=0; i<9; i++)
		for(int j=0; j<9; j++)
		{
			cin>>board[i][j];
			if(board[i][j] > maxValue)
			{
				maxValue = board[i][j];
				maxPos = {i+1, j+1};
			}
		}
	cout<<maxValue<<'\n';
	cout<<maxPos.first<<' '<<maxPos.second<<'\n';
	
	return 0;
} 
