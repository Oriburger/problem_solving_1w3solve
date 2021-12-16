#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
using namespace std;

struct DisjointSet
{
	int n;

	vector<int> parent, size, rank;
	DisjointSet(int n) : n(n), parent(n), size(n, 1), rank(n, 1)
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
		return true;
	}

	int getSize(int u)
	{
		u = find(u);
		return size[u];
	}
};

int n, m, q;
long long ans=0;
vector<pair<int, int> > edges; 
vector<bool> check;
stack<int> stk;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin>>n>>m>>q;

	DisjointSet djs(n);
	check = vector<bool>(m, false);

	//간선의 목록 저장
	for(int i=0; i<m; i++)
	{
		int u, v;
		cin>>u>>v;
		edges.push_back({u-1, v-1});
	}

	//역순으로 진행하기 위한 가장 마지막 상태 만듦
	for(int i=0; i<q; i++)
	{
		int a; cin>>a;
		check[a-1] = true; 
		stk.push(a-1);
	}
	for(int i=0; i<m; i++)
		if(!check[i]) 
			djs.merge(edges[i].first, edges[i].second);

	//오프라인 쿼리 : 역순으로 진행
	//(가장 마지막 상태에서 간선을 추가하며 질의에 답함)
	while(!stk.empty())
	{
		int u, v;
		int curr = stk.top();
		stk.pop();

		u = edges[curr].first;
		v = edges[curr].second;
		
		if(djs.find(u) == djs.find(v)) continue;
		
		ans += (djs.getSize(u) * djs.getSize(v));
		djs.merge(u, v);
	}

	cout<<ans<<'\n';

	return 0;
}
