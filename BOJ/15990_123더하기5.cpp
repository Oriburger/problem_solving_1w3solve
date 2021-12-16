#include <iostream>
#include <vector>
using namespace std;

int n;
long long dp[100001][4] = {0};

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	
	int t;
	
	cin>>t;
	
	dp[1][1]=1;
	dp[2][2]=1;
	dp[3][1]=dp[3][2]=dp[3][3]=1;
	
	for(int i=4; i<=100000; i++)
	{
		dp[i][1] = (dp[i-1][2]+dp[i-1][3])%1000000009;
		dp[i][2] = (dp[i-2][1]+dp[i-2][3])%1000000009;
		dp[i][3] = (dp[i-3][1]+dp[i-3][2])%1000000009;
	}
	
	while(t--)
	{
		cin>>n;
		
		cout<<(dp[n][1]+dp[n][2]+dp[n][3])%1000000009<<'\n';
	}
	
	return 0;
}
