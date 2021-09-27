#include <iostream> 
#include <vector>
#include <algorithm>
#include <utility>
#include <queue>
using namespace std;

typedef pair<int, int> P;
const int INF = 2147000000;

int n, e, v1, v2;
vector<vector<P> > adj;
vector<int> dist;

void Dijkstra(int start)
{
	priority_queue<P, vector<P>, greater<P> > pq;
	
	dist[start]=0;
	pq.push({dist[start], start});
	
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
				pq.push({dist[next], next});
			}
		}
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	
	cin>>n>>e;
	
	adj.resize(n+1);
	dist.resize(n+1, INF);
	
	for(int i=0; i<e; i++)
	{
		int u, v, c;
		cin>>u>>v>>c;
		adj[u].push_back({v, c});
		adj[v].push_back({u, c});
	}
	cin>>v1>>v2;
	
	
	long long stov1, stov2, v1tod, v2tod, v1tov2, v2tov1;
	
	Dijkstra(1);
	stov1 = dist[v1];
	stov2 = dist[v2];
	
	dist.clear(); dist.resize(n+1, INF);
	
	Dijkstra(v1);
	v1tod = dist[n];
	v1tov2 = dist[v2];
	
	dist.clear(); dist.resize(n+1, INF);
	
	Dijkstra(v2);
	v2tod = dist[n];
	v2tov1 = dist[v1];
	
	long long answer1 = stov1 + v1tov2 + v2tod;
	long long answer2 = stov2 + v2tov1 + v1tod;
	
	if(min(answer1, answer2) >= INF)
		cout<<-1<<'\n';
	else
		cout<<min(answer1, answer2)<<'\n';
	
		
	return 0;
}
