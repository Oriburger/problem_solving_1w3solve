#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>
using namespace std;
typedef pair<int, int> P;
const long long INF = 1e18;

int n, m;
bool minCycle;
long long dist[500];
vector<P> adj[500]; 
                    
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin>>n>>m;

	for(int i=0; i<m; i++)
	{	
		int u, v, c;
		cin>>u>>v>>c;
		adj[u-1].push_back({v-1, c});
	}

	fill(dist, dist+n, INF);
	dist[0]=0;
	for(int i=0; i<n; i++)
	{
		for(int j=0; j<n; j++)
		{
			for(auto &p : adj[j])
			{
				int next = p.first, d = p.second;
				if(dist[j] != INF && dist[next] > dist[j] + d)
				{
					dist[next] = dist[j] + d;
					if(i==n-1) minCycle = true;
				}
			}
		}
	}
	if(minCycle)
		cout<<"-1\n";
	else
	{
		for(int i=1; i<n; i++)
			cout<<(dist[i]!=INF ? dist[i] : -1)<<'\n';
	}

	return 0;
}

