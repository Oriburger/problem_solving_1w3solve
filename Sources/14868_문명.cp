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

		return parent[u] = find(parent[u]); //경로 최적화
	}

	void merge(int u, int v)
	{
		u = find(u);
		v = find(v);
		if(u==v) return;

		//랭크에 의한 합치기
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
queue<Pos> q, qq;

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
		board[y-1][x-1]={i+1, 0}; //해당 문명의 id는 i+1
		q.push({y-1, x-1});
	}

	Init(q, djs); //인접한 문명들을 모두 결합해준다.
	
	//이미 모두 결합된 상태라면? 0 출력,
	if(djs.getsize(board[q.front().y][q.front().x].id)==k)
	{
		cout<<0<<'\n';
		return 0;
	}

	int ans = 0;
	while(!q.empty())
	{
		/* 한 턴씩 전파와 결합을 진행한다 */
		int tmp = q.size();
		ans++; //턴 증가.
		
		//문명 전파
		while(tmp--)
		{
			Pos curr = q.front();
			q.pop();

			for(int i=0; i<4; i++)
			{
				int ny = curr.y + dy[i];
				int nx = curr.x + dx[i];

				if(ny<0 || nx<0 || ny>=n || nx>=n) continue;
				if(board[ny][nx].val > 0) continue;
				if(board[ny][nx].val == 0 && board[ny][nx].id != 0) continue;

				q.push({ny, nx});
				qq.push({ny, nx}); //결합에 사용되는 큐에 push
				board[ny][nx]={board[curr.y][curr.x].id
						 	, board[curr.y][curr.x].val+1};
			}
		}

		//문명 결합!
		while(!qq.empty())
		{
			Pos curr = qq.front();
			int curId = board[curr.y][curr.x].id;
			qq.pop();

			for(int i=0; i<4; i++)
			{
				int ny = curr.y + dy[i];
				int nx = curr.x + dx[i];
				if(ny<0 || nx<0 || ny>=n || nx>=n) continue;
				
				int nextId = board[ny][nx].id;

				if(nextId == 0) continue;
				else if(nextId != curId) //서로다른 문명이라면 
				{       
					//이미 결합되었다면  continue; 
					if(djs.find(nextId)==djs.find(curId)) continue;
						
					//문명 결합 
					djs.merge(nextId, curId);
					
					//총 결합된 문명의 수가 k이라면, 
					if(djs.getsize(curId)==k)
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
