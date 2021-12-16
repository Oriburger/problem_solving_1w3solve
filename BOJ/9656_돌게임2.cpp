#include <iostream>
using namespace std;

int n;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin>>n;

	if(n%2==0) cout<<"SK\n";
	else cout<<"CY\n";

	return 0;
}
