#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Edge{ int cost; int u; int v; };
bool CompEdge(const Edge e1, const Edge e2) { return e1.cost < e2.cost; };

struct DisjointSet
{
	int parent[1001], rank[1001];
	DisjointSet(int n)
	{
		for(int i=1; i<n; i++)
		{
			parent[i]=i;
			rank[i]=1;
		}
	}

	int Find(int u)
	{
		if(u==parent[u]) return u;

		return parent[u]=Find(parent[u]); //path compression
	}

	void Merge(int u, int v)
	{
		u = Find(u);
		v = Find(v);

		if(u==v) return;

		if(rank[u] > rank[v]) swap(u, v); //Union by rank
		parent[u]=v; //높이가 더 작은 트리에 추가
		if(rank[u]==rank[v]) rank[v]++;
	}
};

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n, m, total=0;
	int cost[1001][1001]={0};
	vector<Edge> edges, answer;

	cin>>n>>m;

	DisjointSet djs(n+1);
	for(int i=0; i<m; i++)
	{
		int x, y;
		cin>>x>>y;
		djs.Merge(x, y); //이미 연결된 pc들을 연결 (1번pc는 제외)
	}

	for(int i=1; i<=n; i++)
	for(int j=1; j<=n; j++)
		cin>>cost[i][j];

  //1번pc를 제외한 모든 pc를 잇는 간선들의 목록 만듦
	for(int i=2; i<n; i++)
	for(int j=i+1; j<=n; j++)
	{
		if(djs.Find(i)==djs.Find(j)) continue;
		edges.push_back({cost[i][j], i, j});
	}

  //크루스칼 알고리즘을 위한 정렬
	sort(edges.begin(), edges.end(), CompEdge); 

	for(int i=0; i<edges.size(); i++) 
	{
		if(djs.Find(edges[i].u) == djs.Find(edges[i].v)) continue;
		if(answer.size() == n-2) break;
		
		total += edges[i].cost; 
		answer.push_back({0, edges[i].u, edges[i].v});
		djs.Merge(edges[i].u, edges[i].v);
	}

	cout<<total<<' '<<answer.size()<<'\n';
	for(int i=0; i<answer.size(); i++)
		cout<<answer[i].u<<' '<<answer[i].v<<'\n';

	return 0;
}
