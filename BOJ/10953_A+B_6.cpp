#include <iostream>
#include <string>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	
	int t; cin>>t;
	
	while(t--)
	{
		string str;
		cin>>str;
		
		cout<<(int)((str[0]-'0')+(str[2]-'0'))<<"\n";
	}
	
	return 0;
}
