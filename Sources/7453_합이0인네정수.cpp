//https://www.acmicpc.net/problem/7453
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n;
long long ans=0;
vector<int> a, b, c, d;
vector<int> ab, cd;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	
	cin>>n;
	a.resize(n, 0);
	b.resize(n, 0);
	c.resize(n, 0);
	d.resize(n, 0);

	for(int i=0; i<n; i++)
		cin>>a[i]>>b[i]>>c[i]>>d[i];
	
	for(int i=0; i<n; i++)
	{
		for(int j=0; j<n; j++)
		{
			ab.push_back(a[i]+b[j]);
			cd.push_back(c[i]+d[j]);
		}
	}
	sort(cd.begin(), cd.end());

	for(int i=0; i<n*n; i++)
	{
		int cur = ab[i]*-1;
		vector<int>::iterator iterA, iterB;
		
		iterA = lower_bound(cd.begin(), cd.end(), cur);
		iterB = upper_bound(cd.begin(), cd.end(), cur);

		if(*iterA == cur)
			ans += (long long)(iterB - iterA);
	}
	cout<<ans<<'\n';

	return 0;
}
