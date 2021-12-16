#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

int f(int n)
{
	return n<0 ? n*-1 : n;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	while(1)
	{
		int a, b, c, d, cnt=0;
		cin>>a>>b>>c>>d;

		if(!a && !b && !c && !d) break;

		while(1)
		{
			if(a==b && b==c && c==d) break;

			int ta, tb, tc, td;
			ta=f(a-b);
			tb=f(b-c);
			tc=f(c-d);
			td=f(d-a);

			a=ta; b=tb; c=tc; d=td;

			//cout<<a<<' '<<b<<' '<<c<<' '<<d<<'\n';

			cnt++;
		}

		cout<<cnt<<'\n';
	}	

	return 0;
}
