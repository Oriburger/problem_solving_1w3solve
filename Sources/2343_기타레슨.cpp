#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

const int INF = 2147000000;
int n, m, lo=0, hi, mid, ans=INF;
vector<int> l;

bool CanGroup(int k)
{
	int cnt=0, temp=0;
	for(int i=0; i<n; i++)
	{
		if(temp + l[i] > k)
		{
			temp = 0;
			cnt++;
		}
		temp+=l[i];
	}
	if(temp != 0) cnt++;
	
	return cnt <= m;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin>>n>>m;

	l.resize(n);
	for(int i=0; i<n; i++)
	{
		cin>>l[i];
		hi += l[i];
		lo = max(lo, l[i]);
	}

	while(lo<=hi)
	{
		mid = (lo+hi)/2;

		if(CanGroup(mid))
		{
			ans = min(ans, mid);
			hi = mid-1;
		}
		else
			lo = mid+1;
	}

	cout<<ans<<'\n';

	return 0;
}
