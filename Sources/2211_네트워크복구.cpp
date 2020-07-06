#include <iostream>
#include <utility>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

typedef pair<int, int> P;
const int MAX_N = 1001;
const int INF = 2100000000;

vector<P> adj[MAX_N]; //그래프의 인접리스트 표현 adj[u]={v, cost}
vector<bool> visited; //방문체크
vector<int> dist; //각 정점까지의 최단 경로를 저장
vector<int> parents(MAX_N, 0);
priority_queue<P, vector<P>, greater<P> > pq;  //first = cost, second = next 

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int n, m, k;
	
	cin>>n>>m;

	visited.resize(n+1, false);
	dist.assign(n+1, INF);

	for(int i=0; i<m; i++)
	{
		int a, b, c;
		cin>>a>>b>>c;
		adj[a].push_back({b, c});
		adj[b].push_back({a, c});
	}

	dist[1]=0;
	//정렬을 위해 {cost, next} 형식으로 push 
	pq.push({dist[1], 1});

	while(!pq.empty())
	{
		int curr = pq.top().second;
		int currCost = pq.top().first;
		pq.pop();

		//지금 꺼낸 것보다 더 짧은 경로를 알고 있다면
		//지금 꺼낸 것을 무시한다.
		if(dist[curr] < currCost) continue;

		//인접한 정점들을 모두 검사
		for(auto &p : adj[curr])
		{
			int next = p.first;
			int nextDist = p.second + currCost;

			if(dist[next] > nextDist)
			{
				dist[next] = nextDist;
				pq.push({dist[next], next});

				parents[next] = curr;
			}
		}
	}
	cout<<n-1<<'\n';

	for(int i=2; i<=n; i++)
		cout<<parents[i]<<' '<<i<<'\n';

	return 0;
}
