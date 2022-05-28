#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> P;
vector<P> tasks; 
int n, ans; 

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	
	cin>>n;
	
	for(int i=0; i<n; i++)
	{
		int a, b; cin>>a>>b;
		tasks.push_back({a, b});
		ans = max(b, ans);
	}
	
	sort(tasks.begin(), tasks.end(), [](P p1, P p2)->bool
	{
		return p1.second > p2.second;
	});
	
	for(int i=0; i<n; i++)
	{
		ans = min(ans, tasks[i].second); 
		ans -= tasks[i].first;
	}
	cout<<(ans<0 ? -1 : ans)<<'\n';
	
	return 0;
}
