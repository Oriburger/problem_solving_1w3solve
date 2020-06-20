#include <iostream>
using namespace std;

bool yuth[4];
char result[5] = {'E', 'A', 'B', 'C', 'D'};
int cnt;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	
	for(int t=0; t<3; t++)
	{
		cnt=0;
		
		for(int i=0; i<4; i++)
		{
			cin>>yuth[i];
			
			cnt = !(yuth[i]) ? cnt+1 : cnt;
		}
		
		cout<<result[cnt]<<'\n';
	}
	
	return 0;
}
