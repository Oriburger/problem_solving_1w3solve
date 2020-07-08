#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <utility>
using namespace std;

typedef pair<int, int> P;
const int INF = 2147000000;
const int MAX_N = 501;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	while(1)
	{
		int n, m, s, d;
		vector<vector<P> > adj;
		vector<int> dist;

		cin>>n>>m;

		if(n==0 && m==0) break;

		adj.resize(n);
		dist.resize(n, INF);
		
		cin>>s>>d;
		for(int i=0; i<n; i++)
		{
			int u, v, c;
			cin>>u>>v>>c;
			adj[u].push_back({v, c});
		}

		bool flag = false;
		int minDist = INF;
		bool check[MAX_N][MAX_N]={0};

		while(1)
		{
			priority_queue<P, vector<P>, greater<P> > pq;
			vector<int> parents(n, -1);
			
			dist.resize(n, INF);
			dist[s] = 0;
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

					if(check[curr][next]) continue;

					if(dist[next] > nextDist)
					{
						dist[next] = nextDist;
						parents[next] = curr;
						pq.push({dist[next], next});
					}
				}
			}
				
			if(!flag) minDist = dist[d]; //d까지 가는 경로가 없는 경우가 있을까? / 일단 PASS

			else
			{
				if(dist[d] > minDist)
				{
					cout<<dist[d]<<'\n';
					break;
				}
				else if(dist[d] == INF)
				{
					cout<<-1<<'\n';
					break;
				}
				else
				{
					cout<<"ERROR\n";
					break;
				}
			}
			
			if(!flag || minDist == dist[d])
			{
				int curr=d, next=parents[d];
				while(next != -1)
				{
					check[curr][next] = true;
					check[next][curr] = true;

					curr = next;
					next = parents[curr];
				}
			}

			dist.clear();
			flag = true;
		}

		adj.clear();
		dist.clear();
	}

	return 0;
}
