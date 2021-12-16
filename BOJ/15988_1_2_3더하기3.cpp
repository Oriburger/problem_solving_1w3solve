#include <iostream> 
using namespace std;

int t, n;
const long long INF = 1000000009;
long long cache[1000001]={0,1,2,4};

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	
	cin>>t;
	
	while(t--)
	{
		cin>>n;
		
		for(int i=4; i<=n; i++)
		{
			cache[i]=(cache[i-1]%INF+cache[i-2]%INF+cache[i-3]%INF)%INF;
		}
		
		cout<<cache[n]%INF<<'\n';
	}
	
	return 0;
}
