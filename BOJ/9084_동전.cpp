#include <iostream>
#include <cstring>
using namespace std;

int t, n, m;
int coin[21];
int cache[10001];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	
	cin>>t;
	
	while(t--)
	{
		cin>>n;
		
		for(int i=1; i<=n; i++)
			cin>>coin[i];
		
		cin>>m;

		cache[0]=1;
		for(int i=1; i<=n; i++)
		{
			for(int j=coin[i]; j<=m; j++)
				cache[j]+=cache[j-coin[i]];
		}

		cout<<cache[m]<<'\n';
		
		memset(coin, 0, sizeof(coin));
		memset(cache, 0, sizeof(cache));
	}
	
	return 0;
}
