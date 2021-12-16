#include <iostream>
#include <vector>
#include <queue>
#include <utility>
#include <algorithm>
using namespace std;

typedef pair<int, int> P;
const int MAX_N = 1001;
const int INF = 2147000000;

int n, m, start, dest;
vector<P> adj[MAX_N];
vector<int> dist, parent, path;

void Dijkstra()
{
	priority_queue<P, vector<P>, greater<P> > pq;

	dist[start-1]=0;
	parent[start-1]=start-1;
	pq.push({dist[start-1], start-1});
	
	while(!pq.empty())
	{
		int curr = pq.top().second;
		int curDist = pq.top().first;
		pq.pop();

		if(dist[curr] < curDist) continue;

		for(auto &p : adj[curr])
		{
			int next = p.first;
			int nextDist = p.second + curDist;

			if(dist[next] > nextDist)
			{
				dist[next] = nextDist;
				pq.push({dist[next], next});
				parent[next] = curr;
			}
		}
	}

	int v = dest-1;
	path.push_back(v);
	while(parent[v] != v)
	{
		v = parent[v];
		path.push_back(v);
	}
	reverse(path.begin(), path.end());

	cout<<dist[dest-1]<<'\n';
	cout<<path.size()<<'\n';
	for(auto &p : path)
		cout<<p+1<<' ';
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin>>n>>m;
	
	dist = vector<int>(n, INF);
	parent = vector<int>(n, -1);

	for(int i=0; i<m; i++)
	{
		int u, v, cost;
		cin>>u>>v>>cost;
		adj[u-1].push_back({v-1, cost});
	}
	cin>>start>>dest;

	Dijkstra();

	return 0;
}
