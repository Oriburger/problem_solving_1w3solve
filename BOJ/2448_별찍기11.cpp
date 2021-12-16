#include <iostream>
using namespace std;

int n;
bool arr[3500][6500];

void Answer(int y, int x, int len)
{
	if(len==3)
	{
		arr[y][x]=arr[y+1][x-1]=arr[y+1][x+1]=true;
		for(int i=0; i<5; i++) 
			arr[y+2][x-2+i]=true;
		return;
	}

	Answer(y, x, len/2);
	Answer(y+len/2, x-len/2, len/2);
	Answer(y+len/2, x+len/2, len/2);
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	
	cin>>n;

	Answer(0, n-1, n);

	for(int i=0; i<n; i++)
	{
		for(int j=0; j<2*n-1; j++)
			cout<<(arr[i][j] ? '*' : ' ');
		cout<<'\n';
	}

	return 0;
}
