#include <iostream>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int a, b, c, d, tmp=0;
	
	cin>>a>>b>>c>>d;

	tmp = (c+d)/60;
	c = (c+d)%60;

	b+=tmp;
	tmp = b/60;
	b = b%60;

	a+=tmp;
	a = a%24;
	
	cout<<a<<' '<<b<<' '<<c<<'\n';

	return 0;
}
