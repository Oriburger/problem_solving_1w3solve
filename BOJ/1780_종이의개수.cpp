#include <iostream>
#include <cmath>
using namespace std;

int	n, board[2188][2188]={0};
int ans[3]={0};

void Search(int y, int x, int len)
{
	if(y>=n || x>=n || x<0 || y<0) return;

	int a=0, b=0, c=0;
	for(int i=0; i<len; i++)
	{
		for(int j=0; j<len; j++)
		{
			if(board[y+i][x+j]==-1) a++;
			else if(board[y+i][x+j]==0) b++;
			else if(board[y+i][x+j]==1) c++;
		}
	}

	if(a==len*len) ans[0]+=1;
	else if(b==len*len) ans[1]+=1;
	else if(c==len*len) ans[2]+=1;
	else
	{
		Search(y, x, len/3); 

		Search(y, x+len/3, len/3);
		Search(y+len/3, x, len/3);
		Search(y+len/3, x+len/3, len/3);

		Search(y+len/3*2, x, len/3);
		Search(y, x+len/3*2, len/3);

		Search(y+len/3*2, x+len/3, len/3);
		Search(y+len/3, x+len/3*2, len/3);
		Search(y+len/3*2, x+len/3*2, len/3);
	}

	return;
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

	for(auto p : ans)
		cout<<p<<'\n';

	return 0;
}
