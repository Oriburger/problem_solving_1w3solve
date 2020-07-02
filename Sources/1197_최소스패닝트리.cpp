#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Edge{ int cost; int u; int v; }; 

struct DisjointSet
{
	vector<int> parents, ranks;

	DisjointSet(int n) : parents(n+1), ranks(n+1, 1)
	{
		for(int i=0; i<=n; i++)
			parents[i]=i;
	}

	int Find(int u)
	{
		if(parents[u]==u) return u;
		return parents[u]=Find(parents[u]);
	}

	void Merge(int u, int v)
	{
		u = Find(u); v = Find(v);
		if(ranks[u]>ranks[v]) swap(u, v); //u가 무조건 v의 자손으로 들어감
		if(ranks[u]==ranks[v]) ranks[v]++;
		parents[u]=v;
	}
};

bool EdgesComp(Edge a, Edge b)
{
	return a.cost < b.cost;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int v, e, answer=0, cnt=0;

	cin>>v>>e;

	DisjointSet dSet(v);
	vector<Edge> edges;
	
	for(int i=0; i<e; i++)
	{
		int a, b, c;
		cin>>a>>b>>c;
		edges.push_back({c, a, b});
	}
	sort(edges.begin(), edges.end(), EdgesComp);
	
	for(int i=0; i<e; i++)
	{
		int a = edges[i].u;
		int b = edges[i].v;

		if(cnt==v-1) break;
		if(dSet.Find(a) == dSet.Find(b)) continue;

		cnt++;
		dSet.Merge(a, b);
		answer+=edges[i].cost;
	}
	cout<<answer<<'\n';

	return 0;
}
