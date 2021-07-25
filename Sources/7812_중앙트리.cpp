#include <iostream>
#include <vector>
#include <cstring>
#include <utility>
#include <algorithm>
using namespace std;

typedef pair<int, int> P;
typedef long long ll;
const int INF = 2147000000;
const int MAX_N = 10001;

int n;
ll dist[MAX_N]; //0을 루트로 했을 때,
int sub[MAX_N]; //각 정점을 루트로 하는 서브트리의 정점(노드) 개수
vector<vector<P> > adj;

//각 정점당 서브트리의 개수와 
ll InitTree(int curr, int prev)
{
	sub[curr] = 1; //서브 트리는 루트도 포함
	dist[curr] = 0; 

	for(const auto &next : adj[curr])
	{
		if(next.first==prev) continue; //부모로는 올라가지 않음

		dist[curr] += InitTree(next.first, curr); //누적합 
		dist[curr] += next.second * sub[next.first]; //w(curr, next)도 더함
		sub[curr] += sub[next.first]; //서브트리 개수 갱신
	}
	return dist[curr];
}

//DFS를 통해 모든 정점에서의 dist[]값을 도출
void Answer(int curr, int prev) 
{
	for(const auto &next : adj[curr]) 
	{
		if(next.first==prev) continue; //부모로는 올라가지 않는다.

		dist[next.first] = dist[curr] + (n-2*sub[next.first]) * next.second; //점화식
		Answer(next.first, curr); //다음 정점으로..
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	while(1)
	{
		cin>>n;
		if(!n) break;

		adj.resize(n);
		memset(sub, 0, sizeof(sub));
		memset(dist, 0, sizeof(dist));
		for(int i=0; i<n-1; i++)
		{
			int u, v, w;
			cin>>u>>v>>w;
			adj[u].push_back({v, w});
			adj[v].push_back({u, w});
		}

		InitTree(0, -1);
		Answer(0, -1);

		ll ans = 1e18;
		for(int i=0; i<n; i++)
			ans = min(ans, dist[i]); //최소값 출력

		cout<<ans<<'\n';

		adj.clear();
	}

	return 0;
}
