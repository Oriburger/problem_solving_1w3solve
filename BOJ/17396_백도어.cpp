#include <iostream>
#include <vector>
#include <queue>
#include <climits>
#include <utility>
#include <algorithm>
using namespace std;

typedef long long ll;
typedef pair<ll, ll> P;
const ll INF = LLONG_MAX;

ll n, m, ans;
vector<bool> blocked;
vector<vector<P> > adj; 

ll Dijkstra(int start)
{
	vector<ll> dist(n, INF);
	priority_queue<P, vector<P>, greater<P> > pq;
	
	dist[start]=0;
	pq.push({dist[start], start});
	while(!pq.empty())
	{
		int curr = pq.top().second;
		ll curCost = pq.top().first;
		pq.pop();
		
		if(dist[curr] < curCost) continue;
		
		for(auto &p : adj[curr])
		{
			int next = p.first;
			ll nextCost = p.second + dist[curr];
			
			if(blocked[next]) continue;
			if(dist[next] <= nextCost) continue;
			
			dist[next] = nextCost;
			pq.push({dist[next], next});
		}
	}
	return dist[n-1];
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin>>n>>m;

	blocked = vector<bool>(n);
	adj = vector<vector<P> >(n);
	for(int i=0; i<n; i++)
	{
		int tmp; cin>>tmp;
		blocked[i] = (tmp==1);
	}
	blocked[n-1] = false;
	
	for(int i=0; i<m; i++)
	{
		int u, v, cost;
		cin>>u>>v>>cost;
		adj[u].push_back({v, cost});
		adj[v].push_back({u, cost});
	}

	ans = Dijkstra(0);
	cout<<(ans == INF ? -1 : ans)<<'\n';

	return 0;
}
