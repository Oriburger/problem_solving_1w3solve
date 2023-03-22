#include <bits/stdc++.h>
using namespace std;

int n, t, ans = 0;
vector<int> h;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	cin>>n>>t;

	h = vector<int>(n);
	for(int i=0; i<n; i++)
		cin>>h[i];
	
	sort(h.begin(), h.end());

	for(auto &k : h)
	{
		if(t >= k) t++;
		else break;
	}
	cout<<t<<'\n';

	
	return 0;
}
