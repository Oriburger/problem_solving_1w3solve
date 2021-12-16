#include <iostream>
#include <vector>
#include <queue>
#include <utility>
#include <algorithm>
using namespace std;

const int MAX_V = 5001;
const int INF = 2147000000;
typedef pair<int,int> P;

int v, e, p, destDist, mateDist;
vector<P> adj[MAX_V];
vector<int> dist(MAX_V, INF);

int Dijkstra(int start)
{
	priority_queue<P, vector<P>, greater<P> > pq;
	dist[start]=0;
	pq.push({dist[start], start});

	while(!pq.empty())
	{
		int curr = pq.top().second;
		int curCost = pq.top().first;
		pq.pop();

		if(dist[curr] < curCost) continue;

		for(auto &p : adj[curr])
		{
			int next = p.first;
			int nextDist = dist[curr] + p.second;

			if(dist[next] > nextDist)
			{
				dist[next]=nextDist;
				pq.push({nextDist, next});
			}
		}
	}

	return dist[v];
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin>>v>>e>>p;

	for(int i=0; i<e; i++)
	{
		int a, b, c;
		cin>>a>>b>>c;
		adj[a].push_back({b, c});
		adj[b].push_back({a, c});
	}
	destDist = Dijkstra(1);
	mateDist = dist[p];

	dist.clear();
	dist.resize(MAX_V, INF);

	if(mateDist+Dijkstra(p) == destDist)
		cout<<"SAVE HIM\n";
	else
		cout<<"GOOD BYE\n";

	return 0;
}
