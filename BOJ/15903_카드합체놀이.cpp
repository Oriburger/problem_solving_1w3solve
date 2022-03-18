#include <iostream>
#include <queue>
using namespace std;

typedef unsigned long long ull;
priority_queue<ull, vector<ull>, greater<ull> > pq;
ull n, m, ans;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	
	cin>>n>>m;
	
	for(int i=0; i<n; i++)
	{
		ull tmp; cin>>tmp;
		pq.push(tmp);
	}
	
	while(m--)
	{
		ull a[2] = {0, 0};
		for(int i=0; i<2; i++)
		{
			a[i] = pq.top();
			pq.pop();
		}
		
		ull sum = a[0] + a[1];
		for(int i=0; i<2; i++)
			pq.push(sum);
	}
	
	while(!pq.empty())
	{
		ans += pq.top();
		pq.pop();
	}
	
	cout<<ans<<'\n';
	
	return 0;
}
