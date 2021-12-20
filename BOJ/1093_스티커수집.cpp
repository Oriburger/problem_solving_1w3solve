#include <bits/stdc++.h>
using namespace std;
#define FRONT 0
#define BACK 1

const int INF = INT_MAX;
int n, k, tmp, sum, ans;
vector<int> cost, value;
map<int, int> m[2];

void DFS(int curr, const bool isBack, int cost_sum, int value_sum)
{
	if(curr == (!isBack ? n/2 : n))
	{
		if(m[isBack].count(value_sum)==0) m[isBack][value_sum] = cost_sum;
		else m[isBack][value_sum] = min(m[isBack][value_sum], cost_sum);
		return;
	}
	DFS(curr+1, isBack, cost_sum, value_sum);
	DFS(curr+1, isBack, cost_sum + cost[curr], value_sum + value[curr]);
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin>>n;

	value = cost = vector<int>(n);
	for(int i=0; i<n; i++)
		cin>>cost[i];
	for(int i=0; i<n; i++)
		cin>>value[i];

	cin>>k>>tmp;
	
	while(tmp--)
	{
		int id;	cin>>id;
		sum += cost[id];
	}
	
	DFS(0, false, 0, 0);
	DFS(n/2, true, 0, 0);

	tmp = INF;
	auto q = m[BACK].end();
	int r_min = (--q)->second;
	for(auto &p : m[FRONT])
	{
		while(p.first + q->first >= k)
		{
			tmp = min(tmp, p.second + r_min);
			if(q == m[BACK].begin()) break;
			else if(p.first + (--q)->first < k){ q++; break; }
			else r_min = min(r_min, q->second);
		}
	}
	if(tmp == INF) ans = -1;
	else ans = max(tmp - sum, 0);

	cout<<ans<<'\n';

	return 0;
}
