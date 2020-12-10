#include <iostream>
#include <algorithm>
#include <vector>
#include <utility>
using namespace std;

const int MAX_N = 1001;
typedef pair<int, int> P;

struct Edge{ int cost; int u; int v; };
bool CompEdge(const Edge e1, const Edge e2){ return e1.cost < e2.cost; }

int n, m;
char type[MAX_N];
vector<Edge> edges;

struct DisjointSet
{
	vector<int> parent, rank;
	DisjointSet(int n) : parent(n), rank(n, 1)
	{
		for(int i=0; i<n; i++)
			parent[i]=i;
	}

	int Find(int u)
	{
		if(u==parent[u]) return u;
		return parent[u] = Find(parent[u]);
	}

	void Merge(int u, int v)
	{
		u = Find(u); v = Find(v);
		if(u==v) return;

		if(rank[u] > rank[v]) swap(u, v);
		parent[u] = v;
		if(rank[u] == rank[v]) rank[v]+=1;
	}
};

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin>>n>>m;

	for(int i=0; i<n; i++)
		cin>>type[i];

	for(int i=0; i<m; i++)
	{
		int u, v, cost;
		cin>>u>>v>>cost;
		edges.push_back({cost, u-1, v-1});
	}
	sort(edges.begin(), edges.end(), CompEdge);

	int cnt=0, ans=0;
	DisjointSet djs(n);
	for(int i=0; i<m; i++)
	{
		if(djs.Find(edges[i].u) == djs.Find(edges[i].v)) continue;
		if(type[edges[i].u] == type[edges[i].v]) continue;
		if(cnt==n-1) break;

		djs.Merge(edges[i].u, edges[i].v);
		cnt++; ans+=edges[i].cost;
	}
	
	cout<<(cnt==n-1 ? ans : -1)<<'\n';

	return 0;
}
