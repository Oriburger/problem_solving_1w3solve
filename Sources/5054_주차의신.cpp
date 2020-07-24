#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	
	int t; cin>>t;
	
	while(t--)
	{
		int n, sum=0;
		vector<int> arr;
		
		cin>>n;
		arr.resize(n);
		
		for(int i=0; i<n; i++)
			cin>>arr[i];
		
		sort(arr.begin(), arr.end());
		
		for(int i=1; i<n; i++)
			sum+=(arr[i]-arr[i-1]);
		
		cout<<sum*2<<'\n';
	}

	return 0;
}
