#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

typedef unsigned long long ull;

int n;
ull m, lo, hi=0, mid, ans;
vector<ull> t;

ull GetValue(ull k)
{
	ull ret=0;

	for(int i=0; i<n; i++)
		ret+= k / t[i];

	return ret;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin>>n>>m;

	t.resize(n);
	for(int i=0; i<n; i++)
	{
		cin>>t[i];
		hi = max(hi, t[i]);
	}

	lo = 1; hi *= m;
	ans = hi;
	
	while(lo <= hi)
	{
		mid = (lo+hi)/2;

		ull val = GetValue(mid);

		if(val < m)
			lo = mid + 1;
		else
		{
			ans = min(ans, mid);
			hi = mid - 1;
		}
	}

	cout<<ans<<'\n';

	return 0;
}
