#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

const int dy[4]={1, -1, 0, 0};
const int dx[4]={0, 0, -1, 1};
const int MAX = 2001;
const int INF = 100000000;

struct Pos{ int y; int x; };

struct DisjointSet
{
	vector<int> parent, rank;
	DisjointSet(int n) : parent(n), rank(n, 1)
	{
		for(int i=0; i<n; i++)
			parent[i]=i;
	}

	int find(int u)
	{
		if(u==parent[u]) return u;

		return parent[u] = find(parent[u]);
	}

	void merge(int u, int v)
	{
		u = find(u);
		v = find(v);
		if(u==v) return;

		//트리의 높이가 더 높은쪽에 붙여준다.
		if(rank[u] > rank[v]) swap(u, v);
		parent[u] = v;
		if(rank[u] == rank[v]) rank[v]+=1;
	}
};

int n, k;
int board[MAX][MAX];
queue<Pos> q;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin>>n>>k;

	DisjointSet djs(n);
	for(int i=0; i<k; i++)
	{
		int y, x;
		cin>>y>>x;
		board[y][x]=INF+i;
		q.push({y, x});
	}

	while(!q.empty())
	{
		Pos curr = q.front();
		q.pop();
	}

	return 0;
}
