#include <cstdio>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

struct Pos{ int y; int x; };
long double GetDist(const Pos p1, const Pos p2)
{
	return sqrt(pow(p1.y-p2.y, 2) + pow(p1.x-p2.x, 2));
}

struct Edge{ long double cost; int u; int v; };
bool CompEdge(const Edge e1, const Edge e2)
{
	return e1.cost < e2.cost;
}

struct DisjointSet
{
	vector<int> parents, rank;

	DisjointSet(int n) : parents(n+1), rank(n+1, 1)
	{
		for(int i=0; i<=n; i++)
			parents[i]=i;
	}

	int Find(int u)
	{
		if(u==parents[u]) return u;
		return parents[u] = Find(parents[u]); //path compression optimization
	}

	void Merge(int u, int v)
	{
		u = Find(u); v = Find(v);
		if(u==v) return;
		if(rank[u]>rank[v]) swap(u, v); //union by rank optimization
		if(rank[u]==rank[v]) rank[v]++;
		parents[u]=v;
	}
};

int main()
{
	int n, m;
	long double total=0;
	vector<Edge> edges;
	vector<Pos> pos;

	scanf("%d %d", &n, &m);

	for(int i=1; i<=n; i++)
	{
		int y, x;
		scanf("%d %d", &y, &x);
		pos.push_back({y, x});
	}
	
	DisjointSet djs(n); 
	for(int i=0; i<m; i++)
	{
		int a, b;
		scanf("%d %d", &a, &b);
		
		a--; b--;
		if(djs.Find(a)!=djs.Find(b))
			djs.Merge(a, b);
	}

	for(int i=0; i<n-1; i++)
		for(int j=i; j<n; j++)
			edges.push_back({GetDist(pos[i], pos[j]), i, j});

	int cnt=0;
	sort(edges.begin(), edges.end(), CompEdge);
	for(int i=0; i<edges.size(); i++)
	{
		int u = edges[i].u;
		int v = edges[i].v;

		if(djs.Find(u) == djs.Find(v)) continue;

		djs.Merge(u, v);
		cnt++; total+=edges[i].cost;

		if(cnt == n-m-1) break;
	}

	printf("%.2Lf\n", total);

	return 0;
}
