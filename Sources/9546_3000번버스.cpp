#include <iostream>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int t, k;

	cin>>t;

	while(t--)
	{
		long long ans=0;
		
		cin>>k;

		for(int i=0; i<k; i++)
			ans=ans*2+1;

		cout<<ans<<'\n';
	}

	return 0;
}
