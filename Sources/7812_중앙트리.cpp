#include <iostream>
#include <vector>
#include <cstring>
#include <utility>
#include <algorithm>
using namespace std;

typedef pair<int, int> P;
typedef long long ll;
const int INF = 2147000000;
const int MAX_N = 10001;

int n;
ll dist[MAX_N];
int sub[MAX_N];
vector<vector<P> > adj;

ll InitTree(int curr, int prev)
{
	sub[curr] = 1;
	dist[curr] = 0;

	for(const auto &next : adj[curr])
	{
		if(next.first==prev) continue;

		dist[curr] += InitTree(next.first, curr);
		dist[curr] += next.second * sub[next.first];
		sub[curr] += sub[next.first];
	}
	return dist[curr];
}

void Answer(int curr, int prev)
{
	for(const auto &next : adj[curr])
	{
		if(next.first==prev) continue;

		dist[next.first] = dist[curr] + (n-2*sub[next.first]) * next.second;
		Answer(next.first, curr);
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	while(1)
	{
		cin>>n;
		if(!n) break;

		adj.resize(n);
		memset(sub, 0, sizeof(sub));
		memset(dist, 0, sizeof(dist));
		for(int i=0; i<n-1; i++)
		{
			int u, v, w;
			cin>>u>>v>>w;
			adj[u].push_back({v, w});
			adj[v].push_back({u, w});
		}

		InitTree(0, -1);
		Answer(0, -1);

		ll ans = 1e18;
		for(int i=0; i<n; i++)
			ans = min(ans, dist[i]);

		cout<<ans<<'\n';

		adj.clear();
	}

	return 0;
}
