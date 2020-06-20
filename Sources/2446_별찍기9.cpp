#include <iostream>
using namespace std;

int n;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	
	cin>>n;
	
	for(int i=1; i<=2*n-1; i++)
	{
		for(int j=1; j<=2*n-1; j++)
		{
			if(i<=n)
			{
				if(j<i) cout<<' ';
				else if(j>2*n-i) continue;
				else cout<<'*';
			}
			
			else if(i>n)
			{
				if(j<2*n-i) cout<<' ';
				else if(j>i) continue;
				else cout<<'*';
			}
		}
		cout<<'\n';
	}
	
	return 0;
}
