#include <iostream>
using namespace std;

int main()
{
	int n, input, ans=0;

	cin>>n;

	while(n--)
	{
		cin>>input;
		ans+=input-1;
	}
	cout<<ans+1<<'\n';

	return 0;
}
