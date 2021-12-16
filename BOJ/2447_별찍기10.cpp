#include <iostream>
using namespace std;

int n; bool board[6500][6500]={false};

void Answer(int y, int x, int len)
{
	if(y>=n || x>=n || x<0 || y<0) return;
	if(len == 1) return;
	
	Answer(y, x, len/3);
	Answer(y, x+len/3, len/3);
	Answer(y, x+len/3*2, len/3);
	Answer(y+len/3, x, len/3);
	
	
	for(int i = y+len/3; i<y+len-len/3; i++)
		for(int j = x+len/3; j<x+len-len/3; j++)
			board[i][j]=true;
			
	Answer(y+len/3, x+len/3*2, len/3);
	Answer(y+len/3*2, x, len/3);
	Answer(y+len/3*2, x+len/3, len/3);
	Answer(y+len/3*2, x+len/3*2, len/3);
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	
	cin>>n;
	
	Answer(0, 0, n);
	
	for(int i=0; i<n; i++)
	{
		for(int j=0; j<n; j++)
		{
			if(board[i][j]) cout<<' ';
			else cout<<'*';
		}
		cout<<'\n';
	}
	
	
	return 0;
}
