#include <iostream>
using namespace std;

short n, a, b, scoreA=100, scoreB=100;

int main()
{
	cin>>n;

	while(n--)
	{
		cin>>a>>b;

		if(a>b)
			scoreB-=a;
		else if(a<b)
			scoreA-=b;
	}
	
	cout<<scoreA<<'\n';
	cout<<scoreB<<'\n';

	return 0;
}
