#include <iostream>
#include <string>
using namespace std;

int n;
string str;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin>>n;

	while(n--)
	{
		cin>>str;

		for(int i=0; i<(int)str.length(); i++)
		{
			if(str[i]>='A' && str[i]<='Z')
				str[i]+='a'-'A';
		}
		cout<<str<<'\n';
	}

	return 0;
}
