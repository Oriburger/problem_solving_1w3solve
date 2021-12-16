#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>
using namespace std;

typedef pair<int, int> P;
const int MAX_V = 501;
const int INF = 2147000000;

vector<P> adj[MAX_V];

vector<int> bellmanFord(int v, int start)
{
	//시작점을 제외한 모든 정점까지의 최단거리 상한을 INF로
	vector<int> upper(v, INF);
	upper[start]=0;
	bool updated;

	//v번 순회한다.
	for(int i=0; i<v; i++)
	{
		updated = false;
		for(int curr = 0; curr<v; curr++)
		{
			for(auto &p : adj[curr])
			{
				int next = p.first;
				int cost = p.second;
				//(here, there) 간선을 따라 Relax를 시도
				if(upper[next] > upper[curr]+cost)
				{
					upper[next] = upper[curr] + cost;
					updated = true;
				}
			}
		}
		if(!updated) break;
	}
	if(updated) upper.clear();
	return upper;
}

int main()
{
	ios::sync_with_stdio(false);
	cout.tie(NULL); cin.tie(NULL);

	int tc;
	cin>>tc;

	while(tc--)
	{
		int n, m, w, u, v, cost;
		cin>>n>>m>>w;

		for(int i=0; i<=n; i++)
			adj[i].clear();

		for(int i=0; i<m; i++)
		{
			cin>>u>>v>>cost;
			adj[u-1].push_back({v-1, cost});
			adj[v-1].push_back({u-1, cost});
		}
		for(int i=0; i<w; i++)
		{
			cin>>u>>v>>cost;
			adj[u-1].push_back({v-1, -cost});
		}

		vector<int> ans = bellmanFord(n, 0);

		if(ans.size()==0) cout<<"YES\n";
		else cout<<"NO\n";
	}

	return 0;
}
