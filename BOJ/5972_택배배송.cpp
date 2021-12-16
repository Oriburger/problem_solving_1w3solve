#include <iostream>
#include <vector>
#include <queue>
#include <utility>
#include <algorithm>
using namespace std;

typedef pair<int, int> P;
const int INF = 2147000000;
const int MAX_N = 50001;

int n, m;
vector<P> adj[MAX_N];
vector<int> dist(MAX_N, INF);

int Dijkstra(int start)
{
	priority_queue<P, vector<P>, greater<P> > pq;
	dist[start]=0;
	pq.push({dist[start], start});

	while(!pq.empty())
	{
		int cur = pq.top().second;
		int curCost = pq.top().first;
		pq.pop();

		if(dist[cur] < curCost) continue;

		for(const P &p : adj[cur])
		{
			int next = p.first;
			int nextDist = p.second + dist[cur];

			if(dist[next] > nextDist)
			{
				dist[next] = nextDist;
				pq.push({dist[next], next});
			}
		}
	}

	return dist[n];
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin>>n>>m;

	for(int i=0; i<m; i++)
	{
		int a, b, c;
		cin>>a>>b>>c;

		adj[a].push_back({b, c});
		adj[b].push_back({a, c});
	}

	cout<<Dijkstra(1)<<'\n';

	return 0;
}
