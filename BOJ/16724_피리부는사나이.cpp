#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>
using namespace std;

const int dy[4] = {-1, 1, 0, 0};
const int dx[4] = {0, 0, -1, 1};

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
	
	bool merge(int u, int v)
	{
		u = find(u), v = find(v);
		if(u==v) return false;
		if(rank[u] > rank[v]) swap(u, v);
		parent[u] = v;
		if(rank[u]==rank[v]) rank[v]++;
		return true;
	}
};

int n, m, answer;
char board[1001][1001];
bool visited[1001][1001];

Pos GetNextPos(Pos curr, char dir)
{
	int d = -1;
	if(dir == 'U') d = 0;
	else if(dir == 'D') d = 1;
	else if(dir == 'L') d = 2;
	else if(dir == 'R') d = 3;
	
	Pos ret = {curr.y + dy[d], curr.x + dx[d]};
	if(ret.y<0 || ret.x<0 || ret.y>=n || ret.x>=m) return {-1, -1};
	return ret;
}

void DFS(Pos curr, DisjointSet& djs)
{
	visited[curr.y][curr.x] = true;
	
	Pos next = GetNextPos(curr, board[curr.y][curr.x]);
	if(next.y == -1) return;
	if(!djs.merge(curr.y*m + curr.x, next.y*m + next.x)) answer+=1;
	if(!visited[next.y][next.x]) DFS(next, djs);
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	
	cin>>n>>m;
	
	memset(visited, false, sizeof(visited));
	for(int i=0; i<n; i++)
		for(int j=0; j<m; j++)
			cin>>board[i][j];
	
	DisjointSet djs(n*m);
	for(int i=0; i<n; i++)
		for(int j=0; j<m; j++)
			if(!visited[i][j])
				DFS({i, j}, djs);
		
	cout<<answer<<'\n';
		
	return 0;
}
