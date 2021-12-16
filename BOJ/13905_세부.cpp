#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

struct Edge{ int cost; int u; int v; };
bool CompEdge(const Edge &e1, const Edge &e2){ return e1.cost > e2.cost; }

struct DisjointSet
{
	vector<int> rank, parent;
	DisjointSet(int n) : parent(n), rank(n, 1)
	{
		for(int i=0; i<n; i++)
			parent[i]=i;
	}

	int find(int u)
	{
		if(parent[u]==u) return u;
		return parent[u]=find(parent[u]);
	}

	void merge(int u, int v)
	{
		u = find(u); v = find(v);
		if(u==v) return;

		if(rank[u] > rank[v]) swap(u, v);
		parent[u] = v;
		if(rank[u] == rank[v]) rank[v]+=1;
	}
};

const int INF = 2147000000;
typedef pair<int, int> P;

int n, m, s, e;
int cnt=0, ans=INF;
vector<Edge> edges;
vector<vector<P> > adj;
vector<int> dist;
vector<bool> visited;
queue<P> q;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin>>n>>m>>s>>e;

	adj.resize(n+1);
	dist.resize(n+1, INF);
	visited.resize(n+1, false);
	for(int i=0; i<m; i++)
	{
		int a, b, c;
		cin>>a>>b>>c;
		edges.push_back({c, a, b});
	}
	sort(edges.begin(), edges.end(), CompEdge);

	DisjointSet djs(n+1);
	for(int i=0; i<m; i++)
	{
		int u = edges[i].u;
		int v = edges[i].v;
		int cost = edges[i].cost;

		if(djs.find(u) == djs.find(v)) continue;
		if(cnt == n-1) break;

		cnt++;

		adj[u].push_back({v, cost});
		adj[v].push_back({u, cost});
		djs.merge(u, v);
	}
	
	if(djs.find(s)!=djs.find(e))
	{
		cout<<0<<'\n';
		return 0;
	}

	q.push({s, 0});
	visited[s]=true;

	while(!q.empty())
	{
		P curr = q.front();
		q.pop();

		if(curr.first==e) break;

		for(P next : adj[curr.first])
		{ 
			if(visited[next.first]) continue;

			if(curr.first == s) dist[next.first] = next.second;
			else dist[next.first] = min(dist[curr.first], next.second);
			visited[next.first] = true;
			q.push(next);
		}
	}
	
	cout<<dist[e]<<'\n';

	return 0;
}
