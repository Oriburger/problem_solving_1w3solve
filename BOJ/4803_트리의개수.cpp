#include <iostream>
#include <vector>
using namespace std;

struct DisjointSet
{
	vector<int> parent, rank;
	vector<bool> cyclic;

	DisjointSet() { }
	
	void Init(int n)
	{
		cyclic.resize(n, false);
		parent.resize(n, 0);
		rank.resize(n, 1);
		for(int i=0; i<n; i++)
			parent[i]=i;
	}

	void clear()
	{
		parent.clear();
		rank.clear();
		cyclic.clear();
	}

	int find(int u)
	{
		if(u == parent[u]) return u;
		return parent[u]=find(parent[u]);
	}

	void merge(int u, int v)
	{
		u = find(u); v = find(v);
		if(u==v) return;

		if(rank[u] > rank[v]) swap(u, v);
		parent[u] = v;
		if(cyclic[u] || cyclic[v]) //merge시, cyclic 정보도 함께 합친다.
			cyclic[u] = cyclic[v]= true;
		if(rank[u] == rank[v]) rank[v]+=1;
	}

	void setCyclic(int u)
	{
		u = find(u);
		cyclic[u]=true;
	}

	bool isCyclic(int u)
	{
		u = find(u);
		return cyclic[u];
	}
};

int n, m, cnt=1;
DisjointSet djs;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	while(1)
	{
		cin>>n>>m;
		if(n==0 && m==0) break;
		
		int ans = 0;
		djs.Init(n+1);
		for(int i=0; i<m; i++)
		{
			int u, v;
			cin>>u>>v;
			
			//이미 같은 컴포넌트라면
			//같은 간선은 주어지지 않으므로, 사이클이라는 의미
			if(djs.find(u) == djs.find(v))
				djs.setCyclic(u);

			else
				djs.merge(u, v);
		}

		vector<bool> check(n+1, false);
		for(int i=1; i<=n; i++)
		{
			if(!check[djs.find(i)] && !djs.isCyclic(i))
			{
				ans++;
				check[djs.find(i)]=true;
			}
		}

		if(ans==1)	
			cout<<"Case "<<cnt<<": There is one tree.\n";
		else if(ans > 1)
			cout<<"Case "<<cnt<<": A forest of "<<ans<<" trees.\n";
		else
			cout<<"Case "<<cnt<<": No trees.\n";

		djs.clear(); cnt++;
	}

	return 0;
}
