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
		size[v] += size[u];
		parent[u] = v;
		if(rank[u] == rank[v]) rank[v]+=1;
	}

	int getsize(int u)
	{
		u = find(u);

		return size[u];
	}
};

int n, k;
Civ board[MAX][MAX];
queue<Pos> q;

void PrtBoard()
{
	cout<<"==========\n";
	for(int i=0; i<n; i++)
	{
		for(int j=0; j<n; j++)
		{
			cout<<board[i][j].val<<' ';
		}
		cout<<'\n';
	}
	cout<<"==========\n";
}

void Init(queue<Pos> q, DisjointSet &djs)
{
	while(!q.empty())
	{
		Pos curr = q.front();
		int curId = board[curr.y][curr.x].id;
		q.pop();

		for(int i=0; i<4; i++)
		{
			int ny = curr.y + dy[i];
			int nx = curr.x + dx[i];
			if(ny<0 || nx<0 || ny>=n || nx>=n) continue;
			
			int nextId = board[ny][nx].id;
			if(nextId==0) continue;

			djs.merge(nextId, curId);
		}
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin>>n>>k;

	DisjointSet djs(k+1);
	for(int i=0; i<k; i++)
	{
		int y, x;
		cin>>y>>x;
		board[y-1][x-1]={i+1, 0};
		q.push({y-1, x-1});
	}

	Init(q, djs);

	if(djs.getsize(board[q.front().y][q.front().x].id)==k)
	{
		cout<<0<<'\n';
		return 0;
	}	

	while(!q.empty())
	{
		Pos curr = q.front();
		int curId = board[curr.y][curr.x].id;
		q.pop();

		for(int i=0; i<4; i++)
		{
			int ny = curr.y + dy[i];
			int nx = curr.x + dx[i];

			if(ny<0 || nx<0 || ny>=n || nx>=n) continue;
			int nextId = board[ny][nx].id;

			if(nextId != 0)
			{
				if(djs.find(nextId) == djs.find(curId)) continue;
				//cout<<"{"<<ny<<','<<nx<<"} - {"<<curr.y<<','<<curr.x<<"} \n";
				//cout<<nextId<<" - "<<curId<<" is merged\n";
				djs.merge(nextId, curId);

				if(djs.getsize(nextId)==k)
				{
					//cout<<ny<<' '<<nx<<'\n';
					cout<<board[ny][nx].val<<'\n';

					//PrtBoard();

					return 0;
				}
				continue;
			}

			if(board[ny][nx].val > 0) continue;

			q.push({ny, nx});
			board[ny][nx]={board[curr.y][curr.x].id
						 , board[curr.y][curr.x].val+1};
		}
	}


	return 0;
}
