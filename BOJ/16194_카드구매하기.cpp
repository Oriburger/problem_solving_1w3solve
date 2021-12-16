#include <iostream>
using namespace std;

int n, answer=0;
int p[1001];
int cache[1001];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin>>n;

	for(int i=1; i<=n; i++)
		cin>>p[i];

	for(int i=1; i<=n; i++)
	{
		cache[i]=p[i];
		for(int j=1; j<=i/2; j++)
			cache[i] = min(cache[i], cache[j] + cache[i-j]);
	}

	cout<<cache[n]<<'\n';

	return 0;
}
