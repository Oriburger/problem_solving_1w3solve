#include <iostream>
#include <vector>
#include <queue>
#include <utility>
#include <algorithm>
using namespace std;

typedef pair<int, int> P;

int n, m;
const int INF = 2147000000;
vector<int> result, answer;
vector<vector<P> > adj;

vector<int> Dijkstra()
{
	vector<int> dist(m, INF);
	vector<int> ret(m, -1); 
	priority_queue<P, vector<P>, greater<P> > pq;
	
	dist[0] = 0;
	pq.push({dist[0], 0});
	
	while(!pq.empty())
	{
		int curr = pq.top().second;
		int cur_cost = pq.top().first;
		pq.pop();
		
		if(cur_cost > dist[curr]) continue;
		
		for(auto &p : adj[curr])
		{
			int next = p.first;
			int next_cost = p.second;
			
			if(dist[next] <= next_cost + dist[curr]) continue;
						
			ret[next] = curr;
			dist[next] = next_cost + dist[curr];
			pq.push({dist[next], next});
		}
	}
	if(dist[m-1]==INF) return {};
	
	return ret;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	
	int t; cin>>t;
	
	for(int k=1; k<=t; k++)
	{
		cin>>n>>m;
		
		adj = vector<vector<P> >(m);
		for(int i=0; i<n; i++)
		{
			int x, y, cost;
			cin>>x>>y>>cost;
			adj[x].push_back({y, cost});
			adj[y].push_back({x, cost});
		}
		
		result = Dijkstra();
		cout<<"Case #"<<k<<": ";
	
		if(result.empty()) cout<<-1<<'\n';
		else
		{
			int fin = m-1;
			while(1)
			{
				answer.push_back(fin);
				if(fin == 0) break;
				fin = result[fin];
			}
			reverse(answer.begin(), answer.end());
			for(auto &p : answer)
				cout<<p<<' ';
			cout<<'\n';
		}
		result.clear();
		answer.clear();
	}
	
	return 0;
}
