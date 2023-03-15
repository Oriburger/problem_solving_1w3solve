#include <bits/stdc++.h>
using namespace std;

int n; 
bool board[500][500];

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	cin>>n;

	for(int i=n-1; i>=0; i-=1)
	{
		int len = 4 * i + 1;
		int pos = (n-1-i) * 2;
		
		for(int j = 0; j < len; j++)
		{
			board[pos][j+pos] = board[j+pos][pos] = true;
			board[pos+len-1][j+pos] = board[j+pos][pos+len-1] = true;
		}
	}
	
	for(int i=0; i<4*(n-1)+1; i++)
	{
		for(int j=0; j<4*(n-1)+1; j++)
			cout<<(board[i][j] ? '*' : ' ');
		cout<<'\n';
	}
	return 0;
}
