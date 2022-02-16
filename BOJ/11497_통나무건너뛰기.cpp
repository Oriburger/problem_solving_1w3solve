#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;

int t, n, ans;
vector<int> tree, tmp;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	
	cin>>t;
	
	while(t--)
	{
		cin>>n;
		tree = tmp =vector<int>(n);
		for(int i=0; i<n; i++)
			cin>>tree[i];
		
		sort(tree.begin(), tree.end());
		for(int i=0; i<n; i++)
		{
			if(i%2==0) tmp[i/2] = tree[i];
			else tmp[n-i/2-1] = tree[i];
		}
		
		ans = abs(tmp[0]-tmp[n-1]);
		for(int i=0; i<n-1; i++)
			ans = max(ans, abs(tmp[i]-tmp[i+1]));
		
		cout<<ans<<'\n';		
	}
	
	return 0;
}
