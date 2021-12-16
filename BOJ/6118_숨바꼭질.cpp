#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <utility>
using namespace std;

const int INF = 2147000000;

typedef pair<int,int> P;

vector<vector<P> > adj;
vector<int> dist;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int n, m;

	cin>>n>>m;

	adj.resize(n+1);
	dist.resize(n+1, INF);

	for(int i=0; i<m; i++)
	{
		int u, v;
		cin>>u>>v;
		adj[u].push_back({v, 1});
		adj[v].push_back({u, 1});
	}

	priority_queue<P, vector<P>, greater<P> > pq;

	dist[1]=0;
	pq.push({dist[1], 1});

	while(!pq.empty())
	{
		int curr = pq.top().second;
		int currCost = pq.top().first;
		pq.pop();

		if(dist[curr] < currCost) continue;

		for(auto &p : adj[curr])
		{
			int next = p.first;
			int nextCost = p.second + currCost;

			if(dist[next] > nextCost)
			{
				dist[next] = nextCost;
				pq.push({nextCost, next});
			}
		}
	}


	int maxIdx = 0, maxDist = 0, maxCnt=0;
	for(int i=n; i>=1; i--)
	{
		if(maxDist < dist[i])
		{
			maxCnt = 1;
			maxDist = dist[i];
			maxIdx = i;
		}

		else if(maxDist == dist[i])
		{
			maxCnt++;
			maxIdx = i;
		}
	}

	cout<<maxIdx<<' '<<maxDist<<' '<<maxCnt<<'\n';

	return 0;
}
