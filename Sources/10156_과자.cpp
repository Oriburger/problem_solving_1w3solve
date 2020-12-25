#include <iostream>
#include <string>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int k, n, m;
	cin>>k>>n>>m;

	if(k*n > m) cout<<k*n-m<<'\n';
	else cout<<0<<'\n';

	return 0;
}
