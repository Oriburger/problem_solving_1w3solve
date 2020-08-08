#include <iostream>
#include <vector>
#include <climits>
using namespace std;

int dp[1001][1001];

int Answer(int n, int k)
{
	if(dp[n][k]!=0) return dp[n][k];
	if(k==0 || n==k) return dp[n][k]=1;
	
	return dp[n][k]=(Answer(n-1, k)+Answer(n-1, k-1))%10007;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	
	int x, y;
	cin>>x>>y;
	
	cout<<Answer(x, y)<<"\n";
		
	return 0;
}
