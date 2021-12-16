#include <iostream>
#include <vector>
#include <queue>
#include <utility>
#include <algorithm>
using namespace std;

const int MAX_V = 300001;
const int INF = 2147000000;
typedef pair<int,int> P;

int t, v, e, k;
vector<P> adj[MAX_V];
vector<int> dist(MAX_V, INF);
vector<int> mate;

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

	cin>>t;
	
	while(t--)
	{
		cin>>v>>e;

		mate.clear();
		for(int i=0; i<=v; i++)
			adj[i].clear();

		for(int i=0; i<e; i++)
		{
			int a, b, c;
			cin>>a>>b>>c;
			adj[a].push_back({b, c});
			adj[b].push_back({a, c});
		}
		
		cin>>k;
		mate.resize(k);
		for(int i=0; i<k; i++)
			cin>>mate[i];

		int minVal=INF, minIdx=0;
		for(int i=1; i<=v; i++)
		{
			Dijkstra(i);

			int sum=0;
			for(int j=0; j<k; j++)
				sum+=dist[mate[j]];

			if(minVal > sum)
			{
				minVal = sum;
				minIdx = i;
			}

			dist.clear();
			dist.resize(MAX_V, INF);
		}
		cout<<minIdx<<'\n';
	}

	return 0;
}
