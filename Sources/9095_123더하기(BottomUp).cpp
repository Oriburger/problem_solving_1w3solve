#include <iostream> 
using namespace std;

int t, n;
int cache[11]={0,1,2,4};

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	
	cin>>t;
	
	while(t--)
	{
		cin>>n;
		
		for(int i=4; i<=n; i++)
			cache[i]=cache[i-1]+cache[i-2]+cache[i-3];
		
		cout<<cache[n]<<'\n';
	}
	
	return 0;
}
