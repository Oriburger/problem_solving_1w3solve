#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
using namespace std;

struct DisjointSet
{
	int n;

	vector<int> parent, size, rank, cnt;
	DisjointSet(int n) : n(n), parent(n), size(n, 1), rank(n, 1), cnt(n, 0)
	{
		for(int i=0; i<n; i++)
			parent[i]=i;
	}

	int find(int u)
	{
		if(u==parent[u]) return u;
		return parent[u] = find(parent[u]);
	}

	bool merge(int u, int v)
	{
		u = find(u); v = find(v);
		if(u==v) return false;

		if(rank[u] > rank[v]) swap(u, v);
		if(rank[u] == rank[v]) rank[v]+=1;

		parent[u] = v;
		size[v] += size[u];
		cnt[v] += cnt[u];
		return true;
	}

	int getSize(int u)
	{
		u = find(u);
		return size[u];
	}

	int getCnt(int u)
	{
		u = find(u);
		return cnt[u];
	}
};

int n, l;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin>>n>>l;

	DisjointSet djs(l);
	for(int i=0; i<n; i++)
	{
		int a, b;
		bool flag = true;
		cin>>a>>b;
		a -= 1; b -= 1;

		a = djs.find(a);
		b = djs.find(b);

		if(!djs.getCnt(a)) djs.cnt[a]+=1;
		else if(!djs.getCnt(b)) djs.cnt[b]+=1;
		else if(djs.getSize(a) > djs.getCnt(a)) djs.cnt[a]+=1;
		else if(djs.getSize(b) > djs.getCnt(b)) djs.cnt[b]+=1;
		else flag = false;

		if(flag)
		{
			djs.merge(a, b);
			cout<<"LADICA\n";
		}
		else
			cout<<"SMECE\n";
	}

	return 0;
}
