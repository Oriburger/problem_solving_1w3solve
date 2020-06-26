#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int t, n, m, ans;
vector<int> coin;
vector<int> cache;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	
	cin>>t>>n;
	
	while(t--)
	{
		cin>>n;
		
		for(int i=0; i<n; i++)
		{
			int val;
			cin>>val;
			coin.push_back(val);
		}
		cin>>m;
		cache.resize(m+1);
		
		for(int i=0; i<n; i++)
		{
			for(int j=coin[i]; j<=m; j+=coin[i])
			{
				cache[j]++;
			}
		}
		
		cout<<cache[m]<<'\n';
		
		ans=0;
		cache.clear();
		coin.clear();
	}
	
	return 0;
} 
