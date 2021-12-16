#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>
#include <queue>
using namespace std;

typedef pair<int, int> P;

const int INF = 2147000000;
const int MAX_N = 201;

vector<vector<P> > adj;
vector<int> dist;
int Sheet[MAX_N][MAX_N];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int n, m;

	cin>>n>>m;

	adj.resize(n+1);	

	for(int i=0; i<m; i++)
	{
		int u, v, c;
		cin>>u>>v>>c;
		adj[u].push_back({v, c});
		adj[v].push_back({u, c});
	}

	
	for(int start=1; start<=n; start++)
	{	
		dist.resize(n+1, INF);
		priority_queue<P, vector<P>, greater<P> > pq;
		
		dist[start] = 0;
		pq.push({dist[start], start});

		while(!pq.empty())
		{
			int curr = pq.top().second;
			int currCost = pq.top().first;
			pq.pop();

			for(auto &p : adj[curr])
			{
				int next = p.first;
				int nextDist = p.second + currCost;

				if(dist[next] > nextDist)
				{
					dist[next] = nextDist;
					pq.push({nextDist, next});
					Sheet[start][next]=curr; //큐에서 뽑힌 curr은 next의 부모가 된다.
                                   //즉, start가 next일 경우, curr은 처음으로 거쳐야하는 정점이 된다.
				}
			}
		}
		dist.clear();
	}

	for(int i=1; i<=n; i++)
	{
		for(int j=1; j<=n; j++)
		{
			if(i==j) cout<<"- ";
			else
				cout<<Sheet[j][i]<<' ';
		}
		cout<<'\n';
	}

	return 0;
}
