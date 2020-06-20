#include <iostream>
#include <string>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL); 
	
	int n, total=0, score=1;
	string input;
	
	cin>>n; 
	
	while(n--)
	{
		cin>>input;
		
		score=1;
		total=0;
		for(int i=0; i<input.length(); i++)
		{
			if(input[i]=='O')
			{
				total+=score;
				score++;
			}
			else
				score=1;
		}
		cout<<total<<'\n';
	}
	
	return 0;
}
