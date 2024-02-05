#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

int n, ans = 1;
vector<int> arr, cache;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	
	cin>>n;
	
	arr = vector<int>(n, 1);
	for(int i=0; i<n; i++)
		cin>>arr[i];
	
	for(int i=0; i<n; i++)
	{
		cache[i] = 1;
		for(int j=0; j<i; j++)
		{
			if(arr[i] >arr[j]) continue;
			cache[j] = cache[i] + 1;
			ans = max(ans, cache[j]);	
		}
	}
	cout<<ans<<'\n';
	
	return 0;
}
