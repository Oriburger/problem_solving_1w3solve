#include <bits/stdc++.h>
using namespace std;

int n, ans = 0;
vector<int> arr, tmp;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	
	cin>>n;
	arr = vector<int>(n);
	
	for(int i=0; i<n; i++)
		cin>>arr[i];
		
	for(int i=0; i<n-1; i++)
	{
		int max_idx = -1, max_val = -1;
		for(int j=0; j<n-i; j++)
			if(max_val < arr[j])
			{
				max_idx = j;
				max_val = arr[j];
			}
		
		if(max_idx != 0 && max_idx != n-i-1) 
			ans += max_val - max(arr[max_idx-1], arr[max_idx+1]);	
		else if (max_idx == 0)
			ans += max_val - arr[max_idx+1];
		else if (max_idx == n-i-1)
			ans += max_val - arr[max_idx-1];
		
		arr.erase(arr.begin() + max_idx);
	}
	cout<<ans<<'\n';
	
	return 0;
}
