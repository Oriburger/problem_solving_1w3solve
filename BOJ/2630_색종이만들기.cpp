#include <iostream>
using namespace std;

int blue, white;
int n, board[128][128]={0,};

void Search(int y, int x, int len)
{
	if(len==0) return;

	int bCnt=0, wCnt=0;
	for(int i=y; i<y+len; i++)
	{
		for(int j=x; j<x+len; j++)
		{
			bCnt += board[i][j] == 1 ? 1 : 0;
			wCnt += board[i][j] == 1 ? 0 : 1;
		}
	}

	if(bCnt==len*len) blue++;
	else if(wCnt == len*len) white++;

	else
	{
		Search(y+len/2, x+len/2, len/2);
		Search(y, x+len/2, len/2);
		Search(y+len/2, x, len/2);	
		Search(y, x, len/2);
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin>>n;

	for(int i=0; i<n; i++)
	for(int j=0; j<n; j++)
		cin>>board[i][j];

	Search(0, 0, n);

	cout<<white<<'\n'<<blue<<'\n';

	return 0;
}
