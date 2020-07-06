#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>
#include <queue>
using namespace std;

typedef pair<int, int> P;
const int INF = 2147000000;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int t;

	cin>>t;

	while(t--)
	{
		int n, d, c; //컴퓨터 개수, 의존성 개수, 해킹당한 컴퓨터의 개수
		vector<vector<P> > adj;
		vector<int> dist;
		vector<bool> visited;

		cin>>n>>d>>c;

		adj.resize(n+1);
		dist.resize(n+1, INF);
		visited.resize(n+1, false);

		for(int i=0; i<d; i++)
		{
			int a, b, s;
			cin>>a>>b>>s;
			adj[b].push_back({a, s});
		}

		priority_queue<P, vector<P>, greater<P> > pq;

		dist[c]=0;
		pq.push({dist[c], c});
		visited[c]=true;

		while(!pq.empty())
		{
			int curr = pq.top().second;
			int currCost = pq.top().first;
			pq.pop();

			if(dist[curr] < currCost) continue;

			for(auto &p : adj[curr])
			{
				int next = p.first;
				int nextDist = p.second + currCost;

				if(dist[next] > nextDist)
				{
					dist[next] = nextDist;
					pq.push({nextDist, next});
					visited[next]=true;
				}
			}
		}

		int cnt = 0, maxDist=0;
		for(int i=1; i<=n; i++)
		{
			if(visited[i]) cnt++;
			if(maxDist < dist[i] && dist[i] != INF) maxDist = dist[i];
		}

		cout<<cnt<<' '<<maxDist<<'\n';
	}

	return 0;
}
