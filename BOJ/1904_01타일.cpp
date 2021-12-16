#include <iostream>
using namespace std;

int n;
int dp[1000001] = {0,1,2};

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	
	cin>>n;
	
	for(int i=3; i<=n; i++)
		dp[i]=(dp[i-1]+dp[i-2])%15746;
	
	cout<<dp[n]<<'\n';
	
	return 0;	
}
