#include <iostream>
using namespace std;

int n;
int dp[100001]={1,3};

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  
  cin>>n;
  
  for(int i=2; i<=n; i++){
  	dp[i]=(dp[i-1]*2+dp[i-2])%9901;
  }
  
  cout<<dp[n]<<'\n';
  
  return 0;
}
