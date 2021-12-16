#include <iostream>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cout.tie(0); cin.tie(0);

	int n, a=0, b=0;
	cin>>n;

	while(n--)
	{
		int i, j;
		cin>>i>>j;

		if(i>j) a++;
		else if(i<j) b++;
	}
	cout<<a<<' '<<b<<'\n';

	return 0;
}
