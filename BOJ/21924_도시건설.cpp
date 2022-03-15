#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

typedef unsigned long long ull;
struct Edge{ int u; int v; ull cost; };
struct DisjointSet
{
	vector<int> parent, rank;
	
	DisjointSet(int n) : parent(n+1), rank(n+1, 1)
	{
		for(int i=1; i<=n; i++)
			parent[i] = i;
	}
	
	int find(int u)
	{
		if(u == parent[u]) return u;
		return parent[u] = find(parent[u]);
	}
	
	void merge(int u, int v)
	{
		u = find(u), v = find(v);
		if(u==v) return;
		if(rank[u] > rank[v]) swap(u, v);
		parent[u] = v;
		if(rank[u]==rank[v]) rank[v]++;
	}
};

inline bool comp(const Edge &e1, const Edge &e2){ return e1.cost < e2.cost; }

int n, m, cnt;
ull total = 0, sum;
vector<Edge> edges;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	
	cin>>n>>m;
	
	for(int i=0; i<m; i++)
	{
		int u, v; ull c;
		cin>>u>>v>>c;
		total += c;
		edges.push_back({u, v, c});
	}
	
	sort(edges.begin(), edges.end(), comp);
	DisjointSet djs(n);
	for(int i=0; i<edges.size(); i++)
	{
		int u = edges[i].u;
		int v = edges[i].v;
		int cost = edges[i].cost;
		
		if(cnt == n-1) break;
		if(djs.find(u)==djs.find(v)) continue;
		
		cnt++;
		sum += cost;
		djs.merge(u, v);
	}
	
	if(cnt != n-1) cout<<-1<<'\n';
	else cout<<total - sum<<'\n';
	
	return 0;
}
