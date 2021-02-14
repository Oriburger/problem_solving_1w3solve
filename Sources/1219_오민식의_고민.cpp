#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>
using namespace std;

typedef pair<int, int> P;
typedef long long ll;
const int MAX_N = 101;
const ll MIN_INF = -2147000000;
const ll MAX_INF = 2147000000;

int n, m, st, dest;
vector<P> adj[MAX_N];
vector<ll> profit(MAX_N, 0);
vector<ll> upper;
vector<bool> visited(MAX_N, false);

void DFS(int curr)
{
	visited[curr]=true;
	for(auto &p : adj[curr])
	{
		int next = p.first;
		if(!visited[next]) DFS(next);
	}
}

bool bellmanFord(int st)
{
	//시작점을 제외한 모든 정점까지의 최단 거리 상한을 INF로
	upper.resize(n, MIN_INF);
	upper[st] = profit[st];
	vector<bool> check(n, false);

	//n*2번 순회한다
	for(int i=0; i<n*2; i++)
	{
		for(int cur=0; cur<n; cur++)
		{
			for(auto p : adj[cur])
			{
				int next = p.first;
				ll cost = p.second + profit[next];

				//(cur, next) 간선을 따라 완화를 시도
				if(check[cur]) check[next]=true;
				else if(upper[cur]!=MIN_INF && 
							upper[next] < upper[cur] + cost)
				{
					//성공
					if(i>=n-1) check[next] = true;
					else upper[next] = upper[cur] + cost;
				}
			}
		}
	}

	if(check[dest]) return true; //V번째 순회에서도 완화성공? : 사이클 존재
	else return false;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin>>n>>st>>dest>>m;

	for(int i=0; i<m; i++)
	{
		int u, v, cost;
		cin>>u>>v>>cost;
		adj[u].push_back({v, cost*-1});
	}
	for(int i=0; i<n; i++)
		cin>>profit[i];

	DFS(st);
	if(!visited[dest]) 
		cout<<"gg\n";
	else
	{
		int result = bellmanFord(st);

		if(result == true) cout<<"Gee\n";
		else cout<<upper[dest]<<'\n';
	}

	return 0;
}
