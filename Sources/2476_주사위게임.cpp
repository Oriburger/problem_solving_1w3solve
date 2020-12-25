#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int n, ans=0;

	cin>>n;

	for(int i=0; i<n; i++)
	{
		int a, b, c, price=0;

		cin>>a>>b>>c;

		if(a==b && b==c)
			price = 10000 + a * 1000;

		else if(a!=b && b!=c && a!=c)
			price = max(a, max(b, c)) * 100;

		else
		{
			if(a==b) price = 1000 + 100*a;
			else if(b==c) price = 1000 + 100*b;
			else price = 1000 + 100*c;
		}

		ans = max(ans,  price);
	}

	cout<<ans<<'\n';

	return 0;
}
