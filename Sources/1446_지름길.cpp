#include <iostream>
#include <queue>
#include <vector>
#include <utility>
#include <algorithm>
using namespace std;

const int MAX_N = 10001;
const int INF = 2147000000;
typedef pair<int, int> P;

int n, d;
vector<int> dist(MAX_N, INF);
vector<P> adj[MAX_N];

void Dijkstra(int start, int stDist)
{
	priority_queue<P, vector<P>, greater<P> > pq;

	dist[start]=stDist;
	pq.push({dist[start], start});

	while(!pq.empty())
	{
		int curIdx = pq.top().second;
		int curDist = pq.top().first;
		pq.pop();

		if(dist[curIdx] < curDist) continue;

		for(P &next : adj[curIdx])
		{
			int nextIdx = next.second;
			int nextDist = next.first + curDist;

			if(dist[nextIdx] > nextDist)
			{
				dist[nextIdx]=nextDist;
				pq.push({dist[nextIdx], nextIdx});
			}
		}
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin>>n>>d;

	for(int i=0; i<n; i++)
	{
		int u, v, c;
		cin>>u>>v>>c;
		if(u >= v || v-u <= c) continue;
		adj[u].push_back({c, v});
	}
	
	Dijkstra(0, 0);
	for(int i=1; i<=d; i++)
	{	
		dist[i]=min(dist[i-1]+1, dist[i]);
    	Dijkstra(i, dist[i]);
	}
	
	cout<<dist[d]<<'\n';

	return 0;
}
