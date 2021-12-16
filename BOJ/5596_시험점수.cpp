#include <iostream>
using namespace std;

int main()
{
	int ans=0, i=2;
	
	while(i--)
	{
		int a, b, c, d;
		cin>>a>>b>>c>>d;
		ans = max(ans, a+b+c+d);
	}
	
	cout<<ans<<'\n';
	
	return 0;
}
