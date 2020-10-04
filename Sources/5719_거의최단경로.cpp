#include <iostream>
#include <vector>
#include <queue>
#include <utility>
#include <cstring>
#include <algorithm>
using namespace std;

typedef pair<int, int> P;
const int INF = 2147000000;
const int MAX_N = 501;

int n, m, s, d;
vector<int> dist; //최단거리 저장
vector<P> adj[MAX_N]; //그래프
vector<P> radj[MAX_N]; //반대 방향의 간선들이 저장된 그래프
vector<bool> check[MAX_N]; //최단거리 구성 간선들 체크

//다익스트라
void Dijkstra()
{
	priority_queue<P, vector<P>, greater<P> > pq;
	
	dist.clear();
	dist.resize(n);
	dist.assign(n, INF);

	dist[s]=0;
	pq.push({dist[s], s});

	while(!pq.empty())
	{
		int curr = pq.top().second;
		int currCost = pq.top().first;
		pq.pop();

		if(dist[curr] < currCost) continue;

		for(auto &p : adj[curr])
		{
			int next = p.first;
			int nextDist = p.second + currCost;

			//최단경로를 구성하는 간선을 걸러냄
			if(check[curr][next]) continue; 
			
			if(dist[next] > nextDist)
			{
				dist[next] = nextDist;
				pq.push({dist[next], next});
			}
		}
	}
}

//최단경로를 구성하는 간선들은 check!
void EraseEdge()
{
	queue<int> q;
	q.push(d);

	while(!q.empty())
	{
		int curr = q.front();
		q.pop();
		
		//시작 지점을 만난다면
		if(curr==s) continue;

		//그래프를 거꾸로 거슬러 올라가며
		for(auto &p : radj[curr])
		{
			int prev = p.first;
            if(check[prev][curr]) continue;

			//최단경로를 구성하는 간선을 찾는다면
			if(dist[prev] + p.second == dist[curr])
			{
				//체크
				check[prev][curr] = true;
				q.push(prev);
			}
		}
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	while(1)
	{
		cin>>n>>m;
		if(n==0 && m==0) break;

		//컨테이너 초기화
		for(int i=0; i<MAX_N; i++)
		{
			check[i].clear();
			check[i].resize(n, false);
			adj[i].clear();
			radj[i].clear();
		}

		cin>>s>>d;
		for(int i=0; i<m; i++)		
		{
			int u, v, cost;
			cin>>u>>v>>cost;
			adj[u].push_back({v,cost});
			radj[v].push_back({u,cost});
		}
		Dijkstra(); //최단경로를 찾아 dist를 업데이트
		EraseEdge(); //dist기반으로 최단경로를 구성하는 간선들을 체크
		Dijkstra(); //체크된 간선들을 제외하고 다시 최단경로를 찾는다
		
		if(dist[d]==INF) cout<<-1<<'\n';
		else cout<<dist[d]<<'\n';
	}

	return 0;
}
