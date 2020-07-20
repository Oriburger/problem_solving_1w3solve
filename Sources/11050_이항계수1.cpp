#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int n, k;
	int fac[11]={1, 1};

	cin>>n>>k;

	for(int i=1; i<=n; i++)
		fac[i]=fac[i-1]*i;

	cout<<fac[n]/(fac[k]*fac[n-k])<<'\n';

	return 0;
}
