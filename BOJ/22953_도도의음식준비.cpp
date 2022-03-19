#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>
using namespace std;

typedef unsigned long long ull;

const ull INF = 1000000000001;
ull n, k, c, ans = INF;
vector<ull> a;

void GetMinTime()
{
	ull lo = 1, hi = INF;
	while(lo <= hi)
	{
		ull mid = (lo + hi) / 2;
		
		ull tmp = 0;
		for(auto &k : a)
			tmp += mid / k;
			
		if(tmp >= k)
		{
			hi = mid - 1;
			ans = min(ans, mid);
		}
		else lo = mid + 1;
	}
}

void Answer(int t)
{
	GetMinTime();
	if(t==0) return;
	
	for(auto &p : a)
	{
		if(p <= 1) continue;  
		p -= 1;
		Answer(t-1);
		p += 1;
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	
	cin>>n>>k>>c;
	
	a = vector<ull>(n);
	for(int i=0; i<n; i++)
		cin>>a[i];
	
	ans = INF;
	Answer(c);
	cout<<ans<<'\n';
	
	return 0;
}
