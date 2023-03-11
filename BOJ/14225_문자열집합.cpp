#include <bits/stdc++.h>
using namespace std;

int n, m, ans = 0;
unordered_set<string> uset;

int main() 
{
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	cin>>n>>m;

	string str;
	for(int i=0; i<n; i++)
	{
		cin>>str;
		uset.insert(str);
	}

	for(int i=0; i<m; i++)
	{
		cin>>str;
		ans += (uset.find(str) != uset.end());
	}
	cout<<ans<<'\n';
	
	return 0;
}
