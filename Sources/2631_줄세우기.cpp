#include <iostream>
using namespace std;

int arr[200];
int dp[200];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	
	int n, ans=0;
	cin>>n;
	
	for(int i=0; i<n; i++)
		cin>>arr[i];
	
	dp[0]=1;
	for(int i=1; i<n; i++)
	{
		dp[i]=1;
		for(int j=0; j<i; j++)
			if(arr[i] > arr[j] && dp[i] < dp[j]+1)
				dp[i]++;
	}
	
	for(int i=0; i<n; i++)
		ans = max(ans, dp[i]);
		
	cout<<n-ans<<'\n';
	
	return 0;
}
