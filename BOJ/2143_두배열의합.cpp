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
	for(int i=1; i<=n; i++) //a배열에 대한 누적합 구하기
	{
		cin>>a[i];
		s_a[i] = s_a[i-1] + a[i];
	}
	
	cin>>m;
	s_b = b = vector<ll>(m+1);
	for(int i=1; i<=m; i++) //b배열에 대한 누적합 구하기
	{
		cin>>b[i];
		s_b[i] = s_b[i-1] + b[i];
	}
	
	for(int k=0; k<2; k++) //모든 부분합 만들기
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
		
		iter p = mp[1].lower_bound(t-val); //t-val을 B의 부분합 중에서 찾음
		
		if(p==mp[1].end() || p->first + val != t) continue;
		ans += (cnt * p->second);  //mp[0]에서 val이 나오는 부분합 개수 
	}                                // * mp[1]에서 t-val이 나오는 부분합 개수를 더함 
	
	cout<<ans<<'\n';
	
	return 0;
}
