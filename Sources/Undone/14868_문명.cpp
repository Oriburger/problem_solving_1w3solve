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
struct Civ{ int id; int val; };

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

	void merge(int u, int v)
	{
		u = find(u);
		v = find(v);
		if(u==v) return;

		//트리의 높이가 더 높은쪽에 붙여준다.
		if(rank[u] > rank[v]) swap(u, v);
		parent[u] = v;
		size[v] += size[u];
		if(size[v] == n)
		if(rank[u] == rank[v]) rank[v]+=1;
	}

	bool isAllConnected()
	{
		return flag;
	}
};

int n, k;
Civ board[MAX][MAX];
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
		board[y][x]={i+1, 0};
		q.push({y, x});
	}

	while(!q.empty())
	{
		Pos curr = q.front();
		int curId = board[curr.y][curr.x].id;
		q.pop();

		if(djs.isAllConnected())
		{
			cout<<board[curr.y][curr.x].val<<'\n';
			break;
		}

		for(int i=0; i<4; i++)
		{
			int ny = curr.y + dy[i];
			int nx = curr.x + dx[i];
			int nextId = board[ny][nx].id;

			if(ny<0 || nx<0 || ny>=n || nx>=n) continue;
			if(nextId == curId) continue;
			else if(nextId != 0)
			{
				if(djs.find(nextId) == djs.find(curId)) continue;
				djs.merge(nextId, curId);
			}

			q.push({ny, nx});
			board[ny][nx]={board[curr.y][curr.x].id
						 , board[curr.y][curr.x].val+1};
		}
	}

	return 0;
}
