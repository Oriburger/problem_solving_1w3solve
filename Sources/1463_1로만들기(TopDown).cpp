#include <iostream>
#include <cstring> 
using namespace std;

int n;
const int INF=987654321;
int arr[1000001];
int cache[1000001];

int DP(int n)
{
	int& ret = cache[n];
	
	if(n==1) return 0;
	if(ret!=0) return ret; 
	
	if(n%3==0 && n%2==0)
		ret = min(DP(n/3), min(DP(n/2), DP(n-1))) + 1;
	else if(n%2==0)
		ret = min(DP(n/2), DP(n-1))+1;
	else if(n%3==0)
		ret = min(DP(n/3), DP(n-1))+1;
	else
		ret = DP(n-1)+ 1;
	
	return ret;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	
	cin>>n;
	
	cout<<DP(n)<<'\n';
		
	return 0;
}
