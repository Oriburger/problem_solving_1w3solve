#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>
using namespace std;

const int INF = 2147000000;
const int MAX_N = 100000;
const int MAX_DEPTH = 18;
typedef pair<int, int> P;

vector<vector<int> > parent; //parent[i][k] : i의 2^k 번째 부모
vector<vector<int> > maxRoad, minRoad;
vector<int> depth; //정점의 깊이 (0, 1, 2, ...)
vector<P> adj[MAX_N]; //인접 리스트

//DFS 돌며, 2^0번째 부모와 depth 배열 초기화
void MakeTree(P curr)
{
	for(const auto &next : adj[curr.first])
	{
		if(depth[next.first]!=-1) continue;

		parent[next.first][0] = curr.first;
		depth[next.first] = depth[curr.first] + 1;
		maxRoad[next.first][0] = curr.second;
		minRoad[next.first][0] = curr.second;
		MakeTree(next);
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int n, m;
	cin>>n;

	parent.resize(MAX_N, vector<int>(MAX_DEPTH, -1));
	maxRoad.resize(MAX_N, vector<int>(MAX_DEPTH));
	minRoad.resize(MAX_N, vector<int>(MAX_DEPTH));
	depth.resize(MAX_N, -1);
	depth[0]=0;

	for(int i=0; i<n-1; i++)
	{
		int u, v, w;
		cin>>u>>v>>w;

		u-=1; v-=1;
		adj[u].push_back({v, w});
		adj[v].push_back({u, w});
	}

	//트리 만들기
	MakeTree({0, 0});
	
	
	//parent 배열 채움, bottom-up 방식
	for(int j=0; j<MAX_DEPTH-1; j++)
		for(int i=1; i<n; i++)
			if(parent[i][j] != -1)
			{
				parent[i][j+1] = parent[parent[i][j]][j];
				maxRoad[i][j+1] = max(maxRoad[i][j], maxRoad[parent[i][j]][j]);
				minRoad[i][j+1] = min(minRoad[i][j], minRoad[parent[i][j]][j]);
			}
	
	
	cin>>m;
	//m번의 쿼리 수행
	for(int i=0; i<m; i++)
	{
		int u, v;
		int maxAns=-1, minAns=INF;
		cin>>u>>v;

		u-=1; v-=1;

		if(depth[u] < depth[v]) swap(u, v);
		int diff = depth[u] - depth[v];

		//깊이 차이를 없애기 위해 u를 이동시킴.
		for(int j=0; diff; j++)
		{
			if(diff % 2) u = parent[u][j];
			diff /= 2;
		}

		//u와 v가 다르면 동시에 같은 높이만큼 위로 이동.
		if(u != v)
		{
			//높이 2^17, 2^16, ..., 2^1, 2^0 순으로 시도
			for(int j=MAX_N-1; j>=0; j--)
			{
				if(parent[u][j]!=-1 && parent[u][j] != parent[v][j])
				{	
					maxAns = max(maxAns, max(maxRoad[u][j], maxRoad[v][j]));
					minAns = min(minAns, min(minRoad[u][j], minRoad[v][j]));
					u = parent[u][j];
					v = parent[v][j];
				}
			}
			//마지막엔 두 정점 u, v의 부모가 같으므로 한 번 더 올림.
			u = parent[u][0];
		}

		cout<<minAns<<' '<<maxAns<<'\n';
	}

	return 0;
}
