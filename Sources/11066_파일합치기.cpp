#include <iostream>
#include <vector>
#include <climits>
#include <cstring>
using namespace std;

const int INF = 2147000000;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	
	int t, k;
	int cost[501], dp[501][501], sum[502];
	
	cin>>t;
	
	while(t--)
	{
		cin>>k;
		
		memset(cost, 0, sizeof(int)*(k+1));
		memset(sum, 0, sizeof(int)*(k+1));
		for(int i=1; i<=k; i++)
			memset(dp[i], 0, sizeof(int)*(k+1));
		
		for(int i=1; i<=k; i++)
		{
			cin>>cost[i];
			sum[i]=sum[i-1]+cost[i];
		}
		
		for(int d=1; d<k; d++)
		{
			for(int i=1; i+d<=k; i++)
			{
				int j=i+d;
				dp[i][j]=INF;
				
				for(int h=i; h<j; h++)
				{
					int next = dp[i][h]+dp[h+1][j]+sum[j]-sum[i-1];
				
					dp[i][j]=min(dp[i][j], next);
				}
			}
		}
		cout<<dp[1][k]<<"\n";
	}
		
	return 0;
}
