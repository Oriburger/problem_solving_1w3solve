#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n, m;
vector<int> arr, s;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin>>n>>m;
	arr = s = vector<int>(n+1, 0);
	for(int i=1; i<=n; i++)
	{
		cin>>arr[i];
		s[i] = s[i-1] + arr[i];
	}
	
	while(m--)
	{
		int p, q; 
		cin>>p>>q;

		cout<<s[q]-s[p-1]<<'\n';
	}
	
	return 0;
}
