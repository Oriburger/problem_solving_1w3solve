#include <iostream>
using namespace std;

const int INF = 987654321;
int m, n;

int GetAnswer(int y, int x, char board[][50])
{
	int cnt1=0, cnt2=0; //왼쪽위가 검정색일경우, 하얀색일경우  
	
	for(int i=y; i<y+8; i++)
	for(int j=x; j<x+8; j++)
	{
		if((i%2==0 && j%2==1) || (i%2==1 && j%2==0))
		{
			if(board[i][j]=='B') cnt1++;
			else cnt2++;
		}
		else
		{
			if(board[i][j]=='W') cnt1++;
			else cnt2++;
		}
	}
	
	return cnt1 > cnt2 ? cnt2 : cnt1; //둘 중 최소값을 리턴 
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	
	int answer=INF;
	char board[50][50]={0};
	
	cin>>m>>n;
	
	for(int i=0; i<m; i++)
	for(int j=0; j<n; j++)
		cin>>board[i][j];
	
	for(int i=0; i<=m-8; i++) //가능한 보드들을 만든다. 
	for(int j=0; j<=n-8; j++)
		answer = min(answer, GetAnswer(i, j, board)); //최소값 갱신 
	
	cout<<answer<<'\n';
	
	return 0;
}
