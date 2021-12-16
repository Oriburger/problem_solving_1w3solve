#include <iostream>
#include <unordered_map>
#include <string>
#include <vector>
using namespace std;

struct DisjointSet
{
	vector<int> parent, size, rank;

	DisjointSet(int n):parent(n+1),size(n+1, 1),rank(n+1, 1)
	{
		for(int i=0; i<=n; i++)
			parent[i]=i;
	}

	int Find(int u)
	{
		if(parent[u]==u) return parent[u];

		return parent[u] = Find(parent[u]);
	}

	void Merge(int u, int v)
	{
		u = Find(u); v = Find(v);
		if(u==v) return;

		if(rank[u] > rank[v]) swap(u, v);
		size[v] += size[u];
		parent[u]=v; //랭크가 낮은 u를 v의 자식으로 넣음 
		if(rank[u]==rank[v]) rank[v]+=1;
	}

	int GetSize(int u)
	{
		u = Find(u);

		return size[u];
	}

	void Reset()
	{
		parent.clear();
		size.clear();
		rank.clear();
	}
};

int t, f;
unordered_map<string, int> myMap;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin>>t;

	while(t--)
	{
		cin>>f;

		DisjointSet d(f*2);

		int cnt=0;
		for(int i=0; i<f; i++)
		{
			string str1, str2;
			cin>>str1>>str2;

			if(myMap.count(str1)==0)
				myMap.insert({str1, cnt++});
			if(myMap.count(str2)==0)
				myMap.insert({str2, cnt++});

			d.Merge(myMap[str1], myMap[str2]);
			
			cout<<d.GetSize(myMap[str1])<<'\n';
		}

		myMap.clear();
	}

	return 0;
}
