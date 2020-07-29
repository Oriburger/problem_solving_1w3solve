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

		int lcm =0;
		int gcd = GCD(m, n);

		if(gcd == 1) lcm = m*n;
		else lcm = m*n/gcd;

		//cout<<"lcm : "<<lcm<<'\n';

		int temp=x; ans=x;
		for(int i=0; i<lcm; i++)
		{
		//	cout<<temp<<' '<<ans<<'\n';

			temp=temp%n==0 ? n : temp%n;
			
			if(temp==y)	break;
			if(ans-x>lcm)
			{
				ans=-1;
				break;
			}
			
			temp+=m;
			ans+=m;
		}
		
		cout<<ans<<'\n';
	}

	return 0;
}
