#include <iostream>
#include <vector>
using namespace std;

int t, n, cnt=0;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin>>t;

	while(t--)
	{
		cin>>n;

		while(1)
		{
			if(n==0) break;

			if(n%2==1) cout<<cnt<<' ';

			n/=2;
			cnt++;
		}

		cnt=0;
	}

	return 0;
}
