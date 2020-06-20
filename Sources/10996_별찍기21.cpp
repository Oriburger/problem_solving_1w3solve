#include <iostream>
using namespace std;

int n;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	
	cin>>n;
	
	for(int i=1; i<=2*n; i++)
	{
		for(int j=1; j<=n; j++)
		{
			if(i%2==1)
			{
				if(j%2==1) cout<<"*";
				else if(j==n) break; 
				else cout<<" ";
			}
			else 
			{
				if(j%2==0) cout<<"*";
				else if(j==n) break;
				else cout<<" ";
			}
		}
		cout<<'\n';
	}
	
	return 0;
}
