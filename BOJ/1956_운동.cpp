#include <bits/stdc++.h>
using namespace std;

int v, e;
const int INF = 2147000000;
int dist[401][401];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	
	cin>>v>>e;
	
	fill(&dist[0][0], &dist[400][401], INF);
	
	for(int i=0; i<e; i++)
	{
		int a, b, c;
		cin>>a>>b>>c;
		dist[a][b] = min(dist[a][b], c);
	}
	
	for(int k=1; k<=v; k++)
		for(int i=1; i<=v; i++)
			for(int j=1; j<=v; j++)
				if(dist[i][k] != INF && dist[k][j] != INF)
		 	  		dist[i][j] = min(dist[i][j], dist[i][k]+dist[k][j]);
	
	
	int answer = INF;
	for(int i=1; i<=v; i++)
		answer = min(answer, dist[i][i]);
	
	if(answer == INF) cout<<-1<<'\n';
	else cout<<answer<<'\n';
	
	return 0;
}
