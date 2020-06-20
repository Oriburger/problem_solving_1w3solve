#include <iostream>
using namespace std;

int t, n;
int cache[101];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	
	cin>>t;
	
	for(int i=0; i<t; i++)
	{
		cin>>n;
		
		if(cache[n]!=0)
			cout<<cache[n]<<'\n';
		else	
		{
			for(int j=1; j*j<=n; j++)
				cache[n]++;
			
			cout<<cache[n]<<'\n';
		}
	}
	
	return 0;
}
