#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n, m, ans;
bool graph[500][500];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin>>n>>m;

	for(int i=0; i<m; i++)
	{
		int u, v;
		cin>>u>>v;
		graph[u-1][v-1] = true;
	}

	for(int k=0; k<n; k++)
	  for(int i=0; i<n; i++)
	    for(int j=0; j<n; j++)
		  if(graph[i][k] && graph[k][j])
			graph[i][j] = true;

	for(int i=0; i<n; i++)
	{
		int cnt = 0;
		for(int j=0; j<n; j++)
			cnt += (graph[i][j] || graph[j][i]);
		if(cnt == n-1) ans++;
	}

	cout<<ans<<'\n';

	return 0;
}
