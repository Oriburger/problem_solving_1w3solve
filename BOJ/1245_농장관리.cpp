#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>
using namespace std;

int n, m;
vector<vector<int> > dist;
const int INF = 10000001;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin>>n>>m;

	dist = vector<vector<int> >(n, vector<int>(n, INF));
	for(int i=0; i<n-1; i++)
	{
		int u, v, w;
		cin>>u>>v>>w;
		dist[u-1][v-1] = dist[v-1][u-1] = w;
	}

	for(int k=0; k<n; k++)
	{
		for(int i=0; i<n; i++)
		{
			for(int j=0; j<n; j++)
			{
				if(dist[i][j] > dist[i][k] + dist[k][j])
					dist[i][j] = dist[i][k] + dist[k][j];
			}
		}
	}

	for(int i=0; i<m; i++)
	{
		int u, v;
		cin>>u>>v;
		cout<<dist[u-1][v-1]<<'\n';
	}

	return 0;
}
