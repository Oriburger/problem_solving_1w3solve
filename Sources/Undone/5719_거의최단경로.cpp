#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <utility>
using namespace std;

typedef pair<int, int> P;
const int INF = 2147000000;
const int MAX_N = 501;

int n, m, s, d;
vector<vector<P> > adj;
vector<vector<P> > radj;
vector<int> dist;
vector<vector<bool> > check;

void Dijkstra()
{
	priority_queue<P, vector<P>, greater<P> > pq;
	
	dist.clear();
	dist.resize(n, INF);
	dist[s] = 0;
	pq.push({dist[s], s});

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

			if(dist[next] > nextDist && !check[curr][next])
			{
				dist[next] = nextDist;
				pq.push({dist[next], next});
			}
		}
	}
}

void BFS()
{
	queue<int> q;
	q.push(d);
	while(!q.empty())
	{
		int curr = q.front();
		q.pop();
		if(curr == s) continue;
		for(auto &p : radj[curr])
		{
			int prev = p.first;
			int cost = p.second;
			
			if(dist[curr]==dist[prev]+cost)
			{
				check[prev][curr] = true;
				q.push(prev);
			}
		}
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	while(1)
	{
		cin>>n>>m;

		if(n==0 && m==0) break;

		adj.resize(n);
		radj.resize(n);
		dist.resize(n, INF);
		check = vector<vector<bool> >(n, vector<bool>(n,false));
		
		cin>>s>>d;
		for(int i=0; i<m; i++)
		{
			int u, v, c;
			cin>>u>>v>>c;
			adj[u].push_back({v, c});
			radj[v].push_back({u, c});
		}

		Dijkstra(); //첫 최단경로 찾아서 dist 갱신  
		BFS(); //dist값 기준으로 최단경로 역추적 and 삭제 
		Dijkstra(); //거의 최단경로 구함 
		
		if(dist[d]!=INF) cout<<dist[d]<<'\n';
		else cout<<-1<<'\n';
		
		adj.clear();
		radj.clear();
		dist.clear();
		check.clear();
	}

	return 0;
}
