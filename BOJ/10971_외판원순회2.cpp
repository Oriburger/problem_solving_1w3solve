#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n;
int w[10][10];

int TSP(int start, int curr, int visited, int total = 0)
{
	if(visited == (1<<n+1) - 1)
		return w[curr][start] == 0 ? 1e9 : w[curr][start];
	
	int ret = 1e9;
	for(int i=0; i<n; i++)
	{
		if(visited & (1<<i)) continue;
		if(w[curr][i] == 0) continue;
	
		visited |= (1<<i); 
		ret = min(ret, TSP(start, i, visited, total + w[curr][i]) + w[curr][i]);
		visited &= ~(1<<i);
	}
	
	return ret;
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	
	cin>>n;
	
	for(int i=0; i<n; i++)
		for(int j=0; j<n; j++)
			cin>>w[i][j];
		
	int ans = 1e9, visited = 1<<n;
	for(int i=0; i<n; i++)
	{
		visited |= (1<<i);
		ans = min(ans, TSP(i, i, visited));	
		visited &= ~(1<<i);
	}
	
	cout<<ans<<'\n';
	
	return 0;
}
