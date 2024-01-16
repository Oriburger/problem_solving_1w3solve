#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n, m, ans;
vector<int> arr;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	
	cin>>n>>m;
	arr = vector<int>(n, 0);
	for(int i=0; i<n; i++)
		cin>>arr[i];
		
	sort(arr.begin(), arr.end());
	
	for(int i=0; i<n-1; i++)
	{
		int p = arr[i];
		int q = *lower_bound(arr.begin()+i+1, arr.end(), m - p);
		
		if(p + q == m) ans += 1; 
	}
	cout<<ans<<'\n';
	
	return 0;
}
