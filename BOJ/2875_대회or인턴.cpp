#include <iostream>
#include <vector>
using namespace std;

int n, m, k;
int maxCnt=0;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	
	cin>>n>>m>>k;
	
	while(1)
	{
		if(n>1 && m>0)
			maxCnt++;
		
		else break;
		
		n-=2; m-=1;
	}
	
	if(m+n >= k)
		cout<<maxCnt<<'\n';
	
	else
	{
		for(int i=1; i<=maxCnt; i++)
		{
			if((m+n)+i*3 >= k)
			{
				cout<<maxCnt-i<<'\n';
				break;	
			}
		}
	}	

	
	return 0;
}
