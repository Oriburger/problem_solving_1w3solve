#include <iostream>
#include <algorithm>
using namespace std;

int GCD(int a, int b)
{
	if(b==0) return a;

	return GCD(b, a%b);
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	
	int t;

	cin>>t;

	while(t--)
	{
		int m, n, x, y, ans=0;

		cin>>m>>n>>x>>y;

		if(m>n)
		{
			swap(x, y);
			swap(m, n);
		}

		int lcm = m*n/GCD(x, y);

		int temp=x; ans=x;
		
		for(int i=0; i<lcm; i++)
		{
			cout<<temp<<' ';
			temp=temp%n;

			if(temp==0) temp = n;
			if(temp==y) break;

			temp+=m;
			ans+=m;
		}

		cout<<ans<<'\n';
	}

	return 0;
}
