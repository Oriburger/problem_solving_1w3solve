#include <iostream>
#include <vector>
#include <queue>
#include <utility>
#include <algorithm>
using namespace std;

const int MAX_V = 300001;
const int INF = 2147000000;
typedef pair<int,int> P;

int v, e, k, p;
vector<P> adj[MAX_V];
vector<int> dist(MAX_V, INF);

void Dijkstra(int start)
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
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin>>v>>e>>k>>p;

	for(int i=0; i<e; i++)
	{
		int a, b;
		cin>>a>>b;
		adj[a].push_back({b, 1});
	}
	Dijkstra(p);
	
	bool flag = false;
	for(int i=1; i<=v; i++)
		if(dist[i]==k)
		{
			cout<<i<<'\n';
			flag = true;
		}
	
	if(!flag) cout<<-1<<'\n';

	return 0;
}
