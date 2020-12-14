#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Edge{ int cost; int u; int v; }; 

bool CompEdge(Edge a, Edge b){ return a.cost < b.cost; }

struct DisjointSet
{
	vector<int> parents, ranks;

	DisjointSet(int n) : parents(n+1), ranks(n+1, 1)
	{
		for(int i=0; i<=n; i++)
			parents[i]=i;
	}

	int find(int u)
	{
		if(parents[u]==u) return u;
		return parents[u]=find(parents[u]);
	}

	void merge(int u, int v)
	{
		u = find(u); v = find(v);
		if(ranks[u]>ranks[v]) swap(u, v);
		if(ranks[u]==ranks[v]) ranks[v]++;
		parents[u]=v;
	}
};


int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int v, e, p, ans=0, cnt=0;

	cin>>v>>e>>p;

	DisjointSet djs(v);
	vector<Edge> edges;
	vector<bool> pvtx(v+1, 0); //insecure buildings
	vector<int> indegree(v+1, 0);

	for(int i=0; i<p; i++)
	{
		int k; cin>>k;
		pvtx[k]=true;
	}

	for(int i=0; i<e; i++)
	{
		int a, b, c;
		cin>>a>>b>>c;
		edges.push_back({c, a, b});
	}
	sort(edges.begin(), edges.end(), CompEdge);
	
	for(int i=0; i<e; i++)
	{
		int a = edges[i].u;
		int b = edges[i].v;

		if(cnt==v-1) break;
		if(djs.find(a)==djs.find(b)) continue;
		if((pvtx[a] && pvtx[b]) && p!=2) continue;
		if(pvtx[a] && indegree[a]==1) continue;
		if(pvtx[b] && indegree[b]==1) continue;

		//cout<<a<<" - "<<b<<" : "<<edges[i].cost<<'\n';

		cnt++;
		djs.merge(a, b);
		ans+=edges[i].cost;
		indegree[a]++;
		indegree[b]++;
	}

	if(cnt==v-1) cout<<ans<<'\n';
	else cout<<"impossible\n";

	return 0;
}
