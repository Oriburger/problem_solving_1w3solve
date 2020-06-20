#include <iostream>
using namespace std;

int t, n;
long long dp[68]={1,1,2,4};

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  
  cin>>t;
  
  while(t--){
  	cin>>n;
  	
  	if(dp[n]==0)
  	  for(int i=4; i<=n; i++)
  	    dp[i]=dp[i-1]+dp[i-2]+dp[i-3]+dp[i-4];
  	
  	cout<<dp[n]<<'\n';
  }
  
  return 0;
}
