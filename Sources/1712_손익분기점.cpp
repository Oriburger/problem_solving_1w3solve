#include <iostream>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int a, b, c;

	cin>>a>>b>>c;

	if(b>=c) cout<<"-1\n";

	else
	{
		int ans = a/(c-b)+1;

		cout<<ans<<'\n';
	}

	return 0;
}
