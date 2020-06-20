#include <iostream>
#include <algorithm>
using namespace std;

const int INF=1000000000;
int n, m;
int dist[100][100];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	
	cin>>n>>m;
	
	for(int i=0; i<n; i++)
		for(int j=0; j<n; j++)
			dist[i][j] = i==j ? 0 : INF;
	
	for(int i=0; i<m; i++)
	{
		int a, b, c;
		cin>>a>>b>>c;
		
		if(dist[a-1][b-1]==0)
			dist[a-1][b-1]=c;
		else
			dist[a-1][b-1]=min(dist[a-1][b-1], c);
	}
	
	for(int k=0; k<n; k++)
		for(int i=0; i<n; i++)
			for(int j=0; j<n; j++)
				dist[i][j] = min(dist[i][j], dist[i][k]+dist[k][j]);
	
	for(int i=0; i<n; i++)
	{
		for(int j=0; j<n; j++)
		{
			if(dist[i][j]==INF) cout<<0<<' ';
			else cout<<dist[i][j]<<' ';
		}
		cout<<'\n';
	}
	
	return 0;
}
