#include <bits/stdc++.h>
using namespace std;

int n, k;
int lo, hi, mid;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin>>n>>k;

	lo = 1;	hi = k;

	while(lo <= hi)
	{
		mid = (lo+hi)/2;

		int tmp = 0;
		for(int i=1; i<=n; i++)
			tmp += min(mid/i, n);

		if(tmp < k) lo = mid + 1;
		else hi = mid - 1;
	}

	cout<<lo<<'\n';

	return 0;
}
