#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

ll n, c, ans;
vector<ll> arr, front, back;


void DFS(int curr, const int end, int sum)
{
	if(sum > c) return;
	if(curr == end)
	{
		if(end == n/2) front.push_back(sum);
		else back.push_back(sum);
		return;
	}

	DFS(curr+1, end, sum);
	DFS(curr+1, end, sum + arr[curr]);
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin>>n>>c;
	
	arr = vector<ll>(n);
	for(int i=0; i<n; i++)
		cin>>arr[i];
	
	DFS(0, n/2, 0);
	DFS(n/2, n, 0);

	sort(back.begin(), back.end());

	for(auto &p : front)
		ans += upper_bound(back.begin(), back.end(), c-p) - back.begin();

	cout<<ans<<'\n';

	return 0;
}
