#include <bits/stdc++.h>
using namespace std;

int n, m, k, y, x;
int cache[15][15];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	
	cin>>n>>m>>k;
	
	k-=1;
	y = k/m; x = k%m;
	
	for(int i=0; i<15; i++)
	{
		for(int j=0; j<15; j++)
		{
			if(i==0 || j==0) cache[i][j] = 1;
			else cache[i][j] = cache[i-1][j] + cache[i][j-1];
		}
	}
	
	if(k==-1) cout<<cache[n-1][m-1]<<'\n';
	else cout<<cache[y][x] * cache[n-y-1][m-x-1]<<'\n';
	
	return 0;
}
