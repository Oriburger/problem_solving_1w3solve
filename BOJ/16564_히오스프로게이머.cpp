#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

long long n, k;
long long ans = 0;
vector<long long> arr;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	
	cin>>n>>k;
	
	arr = vector<long long>(n);
	for(int i=0; i<n; i++)
		cin>>arr[i];
			
	long long lo = 0, hi = 2000000000;
	while(lo <= hi)
	{
		long long mid = (lo+hi)/2;
		
		long long tmp = 0;
		for(auto &p : arr)
		{
			if(p >= mid) continue;
			else tmp += (mid - p);
		}
		
		if(tmp > k) hi = mid-1;
		else
		{
			lo = mid+1;
			ans = max(ans, mid);
		}
	}
	cout<<ans<<'\n';
	
	return 0;
}
