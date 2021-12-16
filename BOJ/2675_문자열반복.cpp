#include <iostream>
#include <string>
using namespace std;

int t, n;
string str;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	
	cin>>t;
	
	while(t--)
	{
		cin>>n>>str;
		
		for(int i=0; i<str.length(); i++)
			for(int j=0; j<n; j++)
				cout<<str[i];
				
		cout<<'\n';
	}
	
	return 0;
}
