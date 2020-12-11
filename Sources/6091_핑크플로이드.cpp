#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

const int MAX_N = 1025;

struct Edge{ int cost; int u; int v; };
bool CompEdge(const Edge e1, const Edge e2){ return e1.cost < e2.cost; }

int n, m;
vector<Edge> edges;
vector<int> adj[MAX_N];

struct DisjointSet //서로소 집합 (Union-Find 자료구조)
{
	vector<int> parent, rank;
	DisjointSet(int n) : parent(n), rank(n, 1)
	{
		for(int i=0; i<n; i++)
			parent[i]=i;
	}

	int Find(int u)
	{
		if(u==parent[u]) return u;
		return parent[u] = Find(parent[u]);
	}

	void Merge(int u, int v)
	{
		u = Find(u); v = Find(v);
		if(u==v) return;

		if(rank[u] > rank[v]) swap(u, v);
		parent[u] = v;
		if(rank[u] == rank[v]) rank[v]+=1;
	}
};

int main()
{
	ios::sync_with_stdio(false); //속도 향상1
	cin.tie(NULL); cout.tie(NULL); //속도 향상2

	cin>>n;

	int c;
    //인접행렬 입력 i, j에 유의
	for(int i=0; i<n-1; i++) 
	{
		for(int j=i+1; j<n; j++)
		{
			cin>>c;
			edges.push_back({c, i, j});
		}
	}
	sort(edges.begin(), edges.end(), CompEdge); //간선 정렬

	int count=0;
	DisjointSet djs(n);
	for(int i=0; i<(n*n-n)/2; i++) //입력의 크기 만큼 반복
	{
		if(djs.Find(edges[i].u)==djs.Find(edges[i].v))
			continue;

		if(count==n-1) break; //간선이 다 뽑혔다면,,

		count++; //하나 추가
		djs.Merge(edges[i].u, edges[i].v); 
		adj[edges[i].u].push_back(edges[i].v); //인접 리스트에 추가!
		adj[edges[i].v].push_back(edges[i].u); //무향 그래프니까 반대 방향도 챙기기!
	}
	
    //정답 출력
	for(int i=0; i<n; i++)
	{
		sort(adj[i].begin(), adj[i].end());
		cout<<adj[i].size()<<' ';
		for(auto &j : adj[i])
			cout<<j+1<<' ';
		cout<<'\n'; 
	}

	return 0;
}
