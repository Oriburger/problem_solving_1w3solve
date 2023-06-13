#include <iostream>
#include <string>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	int n;
	cin>>n;
	
	while(n--)
	{
		string str;
		cin>>str;
	
		if((str.back()-'0') % 2 == 1) cout<<"odd\n";
		else cout<<"even\n";	
	}
	return 0;
}
