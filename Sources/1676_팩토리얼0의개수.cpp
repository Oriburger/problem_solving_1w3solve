#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int n; cin>>n;

	int ans=0, val=1;
	for(int i=1; i<=n; i++)
	{
		val*=i;

		//cout<<val<<'\n';

		while(1)
		{
			if(val%10!=0)
			{
				val%=10000;
				break;
			}

			ans++;
			val/=10;
		}
	}

	cout<<ans<<'\n';

	return 0;
}
