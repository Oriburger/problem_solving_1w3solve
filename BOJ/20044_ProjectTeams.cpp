#include <bits/stdc++.h>
using namespace std;

int n, ans = 200000;
vector<int> s;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	cin>>n;

	s = vector<int>(n*2);
	for(int i=0; i<n*2; i++)
		cin>>s[i];

	sort(s.begin(), s.end());

	for(int i=0; i<n; i++)
		ans = min(ans, s[i]+s[n*2-1-i]);

	cout<<ans<<'\n';

	return 0;
}
