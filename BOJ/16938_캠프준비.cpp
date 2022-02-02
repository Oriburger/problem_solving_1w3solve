#include <bits/stdc++.h>
using namespace std;

int n, l, r, x, a[15], ans;
const int INF = 2147000000;

void GetAnswer(int idx, int min_val, int max_val, int sum)
{
	if(idx == n)
	{
		if(sum < l || sum > r) return;
		if(abs(min_val - max_val) < x) return;
		ans = ans + 1;
		return;
	}
	GetAnswer(idx+1, min_val, max_val, sum);
	GetAnswer(idx+1, min(min_val, a[idx]), max(max_val, a[idx]), sum+a[idx]);

	return;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin>>n>>l>>r>>x;

	for(int i=0; i<n; i++)
		cin>>a[i];

	GetAnswer(0, INF, 0, 0);

	cout<<ans<<'\n';

	return 0;
}
