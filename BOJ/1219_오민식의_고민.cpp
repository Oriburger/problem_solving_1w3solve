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

int bellmanFord(int st)
{
	//시작점을 제외한 모든 정점까지의 최단 거리 상한을 MIN_INF로
	upper.resize(n, MIN_INF);
	upper[st] = profit[st];
	vector<bool> check(n, false); //무한 사이클에 포함된 정점인지 체크

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
				if(check[cur]) check[next]=true; //무한 사이클에서 도달가능한 정점이라면, 
				else if(upper[cur]!=MIN_INF && 
							upper[next] < upper[cur] + cost)
				{
                    //n-1번의 순회 이후의 완화?
                    //사이클! -> 정점 체크!
					if(i>=n-1) check[next] = true;
					else upper[next] = upper[cur] + cost;
				}
			}
		}
	}

	if(upper[dest]==MIN_INF) return 1; //만약, dest까지 도달이 불가능하다면,
	else if(check[dest]) return 2; //도착 정점이 체크가 되었다면? gee
	return 0;
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
	
	int result = bellmanFord(st);

	if(result == 1) cout<<"gg\n";
	else if(result == 2) cout<<"Gee\n";
	else cout<<upper[dest]<<'\n';

	return 0;
}
