#include <iostream>
using namespace std;

unsigned long long n;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin>>n;

	while(1)
	{
		if(n==1) break;
		if(n%2!=0)
		{
			cout<<0<<'\n';
			return 0;
		}
		n/=2;
	}

	cout<<1<<'\n';

	return 0;
}
