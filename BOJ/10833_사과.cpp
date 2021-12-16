#include <iostream>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	
	int n, answer=0;

	cin>>n;

	for(int i=0; i<n; i++)
	{
		int a, b; cin>>a>>b;

		answer+= (b>=a ? b%a : b);
	}

	cout<<answer<<'\n';

	return 0;
}
