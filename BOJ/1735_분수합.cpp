#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int gcd(int a, int b)
{
	if(b == 0) return a;
	return gcd(b, a%b);
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	
	int a, b, c, d, tmp; //a/b c/d
	cin>>a>>b>>c>>d;
	
	a = a*d + b*c;
	b = b*d;
	tmp = gcd(a, b);
	
	cout<<a/tmp<<' '<<b/tmp<<'\n';
	
	return 0;
}
