#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
#include <algorithm>
using namespace std;

const int MAX = 1501;
const int dy[4] = {1, -1, 0, 0};
const int dx[4] = {0, 0, -1, 1};

struct Pos { int y; int x; };

struct DisjointSet
{
	int n; bool flag;

	//size는 트리에서 백조가 포함된 노드의 개수
	vector<int> parent, rank, size; 
	vector<bool> hasGoose;
	DisjointSet(int n) : n(n), parent(n), rank(n, 1)
						, size(n, 0), hasGoose(n, false)
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
		u = find(u); v = find(v);
		if(u==v) return false;

		if(rank[u] > rank[v]) swap(u, v);
		if(rank[u] == rank[v]) rank[v] += 1;

		size[v]+=size[u];
		parent[u] = v;

		return true;
	}

	void setGoose(const int id)
	{
		size[id] = 1;
		hasGoose[id] = true;
		return;
	}

	int getSize(int u)
	{
		u = find(u);
		return size[u];
	}
};

int r, c;
int board[MAX][MAX];
bool check[MAX][MAX];
vector<Pos> goose;
queue<Pos> combine, propagate;

void Init(Pos start, const int id)
{
	queue<Pos> q;

	board[start.y][start.x] = id;
	q.push(start);

	while(!q.empty())
	{
		Pos curr = q.front();
		q.pop();

		for(int i=0; i<4; i++)
		{
			int ny = curr.y + dy[i];
			int nx = curr.x + dx[i];

			if(ny<0 || nx<0 || ny>=r || nx>=c) continue;
			if(board[ny][nx] > 0) continue;
			else if(board[ny][nx] == -1)
			{
				if(!check[curr.y][curr.x])
				{
					check[curr.y][curr.x] = true;
					propagate.push({curr.y, curr.x});
				}
				continue;
			}

			q.push({ny, nx});
			board[ny][nx] = id;
		}
	}
}

void PrtBoard()
{
	cout<<'\n';
	for(int i=0; i<r; i++)
	{
		for(int j=0; j<c; j++)
		{
			if(board[i][j]==-1) cout<<'X';
			if(board[i][j]>0) cout<<'.';
		}
		cout<<'\n';
	}
	cout<<"-----------\n";
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin>>r>>c;

	for(int i=0; i<r; i++)
	{
		for(int j=0; j<c; j++)
		{
			char temp;
			cin>>temp;
			if(temp=='L') goose.push_back({i, j});
			board[i][j] = (temp == 'X' ? -1 : 0);
		}
	}

	//====구역 id 초기화================
	int cnt=0;
	for(int i=0; i<r; i++)
		for(int j=0; j<c; j++)
			if(!board[i][j])
				Init({i, j}, ++cnt);

	if(cnt==1) //이미 하나로 결합된 경우라면?
	{
		cout<<0<<'\n';
		return 0;
	}

	//====각 구역의 백조 포함 여부 초기화
	DisjointSet djs(cnt+1);
	for(auto &p : goose)
		djs.setGoose(board[p.y][p.x]);

	//====전파와 결합================
	int ans = 0;
	while(!propagate.empty())
//	for(int test=0; test<3; test++)
	{
		int ppgSize = propagate.size();
		ans += 1;

		cout<<"["<<ans<<"] ppgSize : "<<ppgSize<<'\n';

		while(ppgSize--)
		{
			Pos curr = propagate.front();
			int curId = board[curr.y][curr.x];
			combine.push(curr);
			propagate.pop();

			for(int i=0; i<4; i++)
			{
				int ny = curr.y + dy[i];
				int nx = curr.x + dx[i];
				if(ny<0 || nx<0 || ny>=r || nx>=c) continue;
				if(board[ny][nx] > 0) continue;

				
			}		
		}

		PrtBoard();

		while(!combine.empty())
		{
			Pos curr = combine.front();
			int curId = board[curr.y][curr.x];
			combine.pop();

			for(int i=0; i<4; i++)
			{
				int ny = curr.y + dy[i];
				int nx = curr.x + dx[i];

				if(ny<0 || nx<0 || ny>=r || nx>=c) continue;
				if(board[ny][nx]==-1) continue;

				int nextId = board[ny][nx];
				
				if(nextId == curId) continue;
				else
				{
					if(djs.find(curId)==djs.find(nextId)) continue;

					djs.merge(curId, nextId);
					if(djs.getSize(curId)==2)
					{
						cout<<ans<<'\n';
						return 0;
					}
				}
			}
		}
	}
	cout<<ans<<'\n';

	return 0;
}
