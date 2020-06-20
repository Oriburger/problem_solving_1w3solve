#include <iostream>
using namespace std;

int l, b, a, c, d;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	
	cin>>l>>a>>b>>c>>d;
	
	cout<<l - max(a/c + (a%c>0 ? 1 : 0), b/d + (b%d>0 ? 1 : 0))<<'\n';
	
	return 0;
}
