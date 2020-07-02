#include <iostream>
#include <vector>
using namespace std;

struct DisjointSet
{
	vector<int> parent, rank;

	DisjointSet(int n):parent(n), rank(n, 1)
	{
		for(int i=0; i<n; i++)
			parent[i]=i;
	}

	int Find(int u)
	{
		if(parent[u]==u) return u;

		return parent[u] = Find(parent[u]);
	}

	void Merge(int u, int v)
	{
		u = Find(u); v = Find(v);
		
		if(u==v) return;

		if(rank[u]>rank[v]) swap(u, v);
		if(rank[u]==rank[v]) rank[v]++;
		parent[u] = v;
	}
};

int n, m;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin>>n>>m;

	DisjointSet d(n+1);
	for(int i=0; i<m; i++)
	{
		int cmd, a, b;

		cin>>cmd>>a>>b;

		if(cmd==1)
		{
			if(d.Find(a)==d.Find(b)) cout<<"yes\n";
			else cout<<"no\n";
		}

		else if(cmd==0)
			d.Merge(a, b);
	}

	return 0;	
}
