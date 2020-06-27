#include <iostream> 
using namespace std;

int t, n;
int cache[11]={0,1,2,4};

int DP(int n)
{
	int& ret = cache[n];
	
	if(n<4) return ret;
	if(ret!=0) return ret;
	
	return ret = DP(n-1)+DP(n-2)+DP(n-3);
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	
	cin>>t;
	
	while(t--)
	{
		cin>>n;
		
		cout<<DP(n)<<'\n';
	}
	
	return 0;
}
