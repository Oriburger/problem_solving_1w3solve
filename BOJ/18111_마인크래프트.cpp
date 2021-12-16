#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int n, m, b;
	int ansHeight=0, ansSec=2147000000;
	cin>>n>>m>>b;

	vector<int> board(n*m);
	
	for(int i=0; i<n*m; i++) cin>>board[i];
	sort(board.begin(), board.end(), greater<int>());

	for(int h=board[0]; h>=board[n*m-1]; h--)
	{
		int total = 0;
		int inven = b;

		for(int i=0; i<n*m; i++)
		{
			if(board[i] > h)
			{
				inven += board[i]-h;
				total += 2*(board[i]-h);
			}
			else if(board[i] < h)
			{
				inven -= h-board[i];
				if(inven < 0) break;
				total += (h-board[i]);
			}
		}

		if(inven >= 0)
		{
			if(total == ansSec)
				ansHeight = max(ansHeight, h);
			else if(total < ansSec)
			{
				ansSec = total;
				ansHeight = h;
			}
		}
	}

	cout<<ansSec<<' '<<ansHeight<<'\n';

	return 0;
}
