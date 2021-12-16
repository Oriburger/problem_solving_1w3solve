#include <iostream>
#include <cmath>
using namespace std;

int n, ans=0;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	
	cin>>n;

	for(int i=1; i<=n; i*=10)
		ans += n-i+1;

	cout<<ans<<'\n';

	return 0;
}
