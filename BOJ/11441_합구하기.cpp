#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int n, q; 
vector<int> arr, sum;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	
	cin>>n;
	
	arr = sum = vector<int>(n+1, 0);
	for(int i=0; i<n; i++)
	{
		cin>>arr[i];
		
		if(i==0) sum[i] = arr[i];
		else sum[i] = sum[i-1] + arr[i];
	}
	
	cin>>q;
	while(q--)
	{
		int p, q;
		cin>>p>>q;
		
		p--; q--;
		
		if(p == 0) cout<<sum[q]<<'\n';
		else cout<<sum[q] - sum[p-1]<<'\n';
	}
	
	return 0;
}
