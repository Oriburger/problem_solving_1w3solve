#include <iostream>
#include <vector>
#include <algorithm>
#define INF 2147000000
using namespace std;

int n, ans=0;
vector<int> arr, cache;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin>>n;

	cache.resize(n+1, INF);
	
	cache[0]=0;
	cache[1]=1;
	for(int i=2; i<=n; i++)
	{
		int temp = INF;
		for(int j=1; j*j<=i; j++)
			temp=min(cache[i-j*j]+1, temp);
		cache[i]=temp;
	}

	cout<<cache[n]<<'\n';

	return 0;
}
