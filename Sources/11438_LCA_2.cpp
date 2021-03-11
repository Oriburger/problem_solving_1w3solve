#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

const int MAX_N = 100000;
const int MAX_DEPTH = 18;

vector<vector<int> > parent; //parent[i][k] : i의 2^k번째 부모
vector<int> adj[MAX_N]; //인접 리스트
vector<int> depth; //정점의 깊이 (루트의 깊이 : 0)

//DFS 기반 함수 : 트리를 만들며 parent[k][0], depth 초기화
void MakeTree(int curr) 
{
	for(const int &next : adj[curr])
	{
		if(depth[next]!=-1) continue;

		parent[next][0] = curr; 
		depth[next] = depth[curr]+1;
		MakeTree(next);
	}
}

int GetLCA(int u, int v) //u와 v의 LCA를 반환
{
	if(depth[u] < depth[v]) swap(u, v);
	int diff = depth[u] - depth[v];

	//u와 v의 깊이가 같아지도록 u를 이동시킴
	for(int h=0; diff; h++)
	{
		if(diff%2) u = parent[u][h];
		diff/=2;
	}

	//u와 v가 다르면, 동시에 일정 높이만큼 위로 이동
	if(u!=v)
	{
		//큰 순으로 시도, -> 최대한 적게 이동하기 위함
		for(int h=MAX_DEPTH-1; h>=0; h--)
		{
			if(parent[u][h] == -1) continue;
			if(parent[u][h] == parent[v][h]) continue;

			u = parent[u][h];
			v = parent[v][h];
		}
		u = parent[u][0];
	}

	return u;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int n, m;

	//컨테이너 초기화
	parent.resize(MAX_N, vector<int>(MAX_DEPTH, -1));
	depth.resize(MAX_N, -1); 
	depth[0]=0;
	
	cin>>n;
	for(int i=0; i<n-1; i++)
	{
		int u, v;
		cin>>u>>v;
		
		u-=1; v-=1;

		adj[u].push_back(v);
		adj[v].push_back(u);
	}

	//트리 만들기 
	MakeTree(0);

	//parent 배열 채움 : bottom-up 방식
	for(int h=0; h<MAX_DEPTH-1; h++)
		for(int i=1; i<n; i++)
			if(parent[i][h] != -1)
				parent[i][h+1] = parent[parent[i][h]][h];

	cin>>m; //m번의 쿼리
	for(int i=0; i<m; i++)
	{
		int u, v;
		cin>>u>>v;

		u-=1; v-=1;

		cout<<GetLCA(u, v)+1<<'\n';
	}

	return 0;
}
