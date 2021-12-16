#include <iostream>
#include <queue>
using namespace std;

int t, n, scoreA, scoreB;

bool GetWinner(char a, char b)
{
	if(a=='R')
	{
		if(b=='P') return false;
		else return true;
	}

	else if(a=='S')
	{
		if(b=='R') return false;
		else return true;
	}
	
	else if(a=='P')
	{
		if(b=='S') return false;
		else return true;
	}

	return false;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin>>t;

	while(t--)
	{
		cin>>n;

		scoreA=scoreB=0;
		
		for(int i=0; i<n; i++)
		{
			char a, b;
			cin>>a>>b;

			if(a==b) 
				continue;
			else if(GetWinner(a, b))
				scoreA++;
			else
				scoreB++;
		}

		if(scoreA == scoreB)
			cout<<"TIE\n";

		else
			cout<<(scoreA > scoreB ? "Player 1\n" : "Player 2\n");
	}

	return 0;
}
