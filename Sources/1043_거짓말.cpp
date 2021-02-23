#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct DisjointSet
{
	vector<int> parent, rank;
	vector<bool> truth;
	DisjointSet(int n, vector<bool> t) : parent(n), rank(n, 1), truth(n, false)
	{
		for(int i=0; i<n; i++) parent[i]=i;
		for(int i=0; i<t.size(); i++) truth[i]=t[i];
	}

	int find(int u)
	{
		if(u==parent[u]) return u;
		return parent[u] = find(parent[u]);
	}

	void merge(int u, int v)
	{
		u = find(u); v = find(v);
		if(u==v) return;

		if(rank[u] > rank[v]) swap(u, v);
		parent[u] = v;
		if(truth[u] || truth[v]) truth[parent[u]]=true;
		if(rank[u] == rank[v]) rank[v] += 1;
	}

	void prt_state()
	{
		for(int i=0; i<rank.size(); i++)
			cout<<i<<" : "<<truth[i]<<'\n';
		cout<<'\n';
	}
};

const int MAX_N = 51;
int n, m, t;
vector<bool> truth(MAX_N);

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin>>n>>m>>t;

	for(int i=0; i<t; i++)
	{
		int id; cin>>id;
		truth[id-1]=true;
	}

	DisjointSet djs(n+m, truth);

	for(int i=0; i<m; i++)
	{
		int k; cin>>k;
		for(int j=0; j<k; j++)
		{
			int id; cin>>id;
			djs.merge(i+n, id-1);
		}
	}

	if(t==0)
	{
		cout<<m<<'\n';
		return 0;
	}

	int ans=0;
	for(int i=n; i<n+m; i++)
		if(!djs.truth[djs.find(i)]) ans++;

	cout<<ans<<'\n';

	return 0;
}
