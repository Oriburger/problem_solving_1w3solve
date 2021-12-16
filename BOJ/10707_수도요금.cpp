#include <iostream>
using namespace std;

int a, b, c, d, p;
int x, y;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	
	cin>>a>>b>>c>>d>>p;
	
	x = p*a;
	y = p>c ? b + d*(p-c) : b;
	
	cout<<min(x, y)<<'\n';
	
	return 0;
}
