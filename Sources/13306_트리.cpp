#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <algorithm>
using namespace std;

struct DisjointSet
{
	int n; bool flag;
	vector<int> parent, rank, size;
	DisjointSet(int n) : n(n), parent(n), rank(n, 1), size(n, 1)
	{
		flag = false; 
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
		u = find(u);
		v = find(v);
		if(u==v) return false;

		parent[u] = v;
		return true;
	}

};
struct Query{ int id; int a; int b; };

int n, q;
vector<Query> query;
vector<int> parent;
stack<bool> ans;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin>>n>>q;
	DisjointSet djs(n+1);
	parent.resize(n+1, 0);

	for(int i=2; i<=n; i++)
		cin>>parent[i];
	
	q = q+(n-1);
	for(int i=0; i<q; i++)
	{
		int x, a, b;
		cin>>x;

		if(!x)
		{
			cin>>a;
			query.push_back({x, parent[a], a});
		}
		else
		{
			cin>>a>>b;
			query.push_back({x, a, b});
		}
	}

	for(int i=q-1; i>=0; i--)
	{
		if(!query[i].id)
			djs.merge(query[i].a, query[i].b);
		else
		{
			if(djs.find(query[i].a)==djs.find(query[i].b)) ans.push(true);
			else ans.push(false);
		}
	}

	while(!ans.empty())
	{
		cout<<(ans.top() ? "YES\n" : "NO\n");
		ans.pop();
	}

	return 0;
}
