#include <iostream>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int a, b, c, temp=0;
	
	cin>>a>>b>>c;

	temp = (b+c)/60;
	b=(b+c) < 60 ? b+c : (b+c)%60 ;
	a+=temp;
	a%=24;

	cout<<a<<' '<<b<<'\n';

	return 0;
}
