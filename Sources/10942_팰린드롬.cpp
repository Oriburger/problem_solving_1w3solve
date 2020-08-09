#include <iostream>
#include <vector>
#include <climits>
#include <cstring>
using namespace std;

int n, m, arr[2001], dp[2001][2001];

int Answer(int s, int e)
{
    if(dp[s][e]!=-1) return dp[s][e];
    if(s==e) return dp[s][e]=arr[s]==arr[e];
    if(s-1==e) return true;

    if(arr[s]==arr[e]) dp[s][e]=true;
    else
    {
        dp[s][e]=false;
        return dp[s][e];
    }
    
    for(int i=1; s+i<=e-i; i++)
        dp[s][e]=dp[s][e]&&Answer(s+i,e-i);
        
    return dp[s][e];
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	
	cin>>n;
	for(int i=0; i<n; i++)
	{
		cin>>arr[i];
		memset(dp[i], -1, sizeof(int)*n);
	}
	
	cin>>m;	
	for(int i=0; i<m; i++)
	{
	    int s, e;
	    cin>>s>>e;
	    
	    cout<<Answer(s-1, e-1)<<"\n";
	}
	
	return 0;
}
