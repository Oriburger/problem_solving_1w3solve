#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>
using namespace std;

int ans=0, n;
vector<int> board[5];
vector<bool> check[5];

bool IsBingo()
{
	int cnt=0;

	if(check[0][0] && check[1][1] && 
	   check[2][2] && check[3][3] && check[4][4]) 
		cnt++;
	
	if(check[4][0] && check[3][1] &&
	   check[2][2] && check[1][3] && check[0][4])
	   	cnt++;

	for(int i=0; i<5; i++)
	{
		if(check[i][0] && check[i][1] && 
		   check[i][2] && check[i][3] && check[i][4])
			cnt++;

		if(check[0][i] && check[1][i] && 
		   check[2][i] && check[3][i] && check[4][i])
			cnt++;
	}
	
	return cnt>=3;
}

pair<int, int> GetBoardPos(int num)
{
	for(int i=0; i<5; i++)
		for(int j=0; j<5; j++)
			if(board[i][j]==num)
				return {i, j};

	return {0, 0};
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	for(int i=0; i<5; i++)	
	{
		board[i].resize(5, 0);
		check[i].resize(5, false);
		for(int j=0; j<5; j++)
			cin>>board[i][j];
	}

	for(int i=0; i<25; i++)
	{
		cin>>n;

		pair<int,int> pos = GetBoardPos(n);
		check[pos.first][pos.second]=true;

		if(IsBingo())
		{
			ans=i+1;
			break;
		}
	}
	cout<<ans<<'\n';

	return 0;
}
