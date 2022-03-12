#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;

typedef long long ll;		
typedef map<ll, ll>::iterator iter;

ll t, n, m, ans;
vector<ll> a, b, s_a, s_b;
	
map<ll, ll> mp[2];
	
int main()
{	
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	
	cin>>t>>n;
	
	s_a = a = vector<ll>(n+1);
	for(int i=1; i<=n; i++)
	{
		cin>>a[i];
		s_a[i] = s_a[i-1] + a[i];
	}
	
	cin>>m;
	s_b = b = vector<ll>(m+1);
	for(int i=1; i<=m; i++)
	{
		cin>>b[i];
		s_b[i] = s_b[i-1] + b[i];
	}
	
	for(int k=0; k<2; k++)
	{
		for(int i=0; i<(k==0 ? n : m); i++)
		{
			for(int j=i+1; j<=(k==0 ? n : m); j++)
			{
				ll sum = (k==0 ? s_a[j] - s_a[i] : s_b[j] - s_b[i]);
				if(mp[k].count(sum)==0) mp[k][sum]=1;
				else mp[k][sum]+=1;
			}
		}
	}
	
	iter it = mp[0].begin();
	for(it; it != mp[0].end(); it++)
	{
		ll val = it->first; 
		ll cnt = it->second;
		
		iter p = mp[1].lower_bound(t-val);
		
		if(p==mp[1].end() || p->first + val != t) continue;
		ans += (cnt * p->second);		
	}
	
	cout<<ans<<'\n';
	
	return 0;
}
